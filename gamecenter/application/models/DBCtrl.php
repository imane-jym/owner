<?php

class DBctrl extends Model {

	public function Init()
	{
		global $config;
		parent::Init($config['db_host'], $config['db_name'], $config['db_username'], $config['db_password']);
	}
	
	public function ExistIndex($table, $index)
	{
		global $config;
		$table = $this->escapeString($table);
		$index = $this->escapeString($index);
		$result = $this->query("select * from information_schema.statistics where table_name='{$table}' and index_name='{$index}' and table_schema = '{$config['db_name']}'");
		return count($result);
	}

	public function ExistColumn($table, $col)
	{
		global $config;
		$table = $this->escapeString($table);
		$col = $this->escapeString($col);
		$result = $this->query("select * from information_schema.columns where table_name='{$table}' and column_name='{$col}' and table_schema = '{$config['db_name']}'");
		return count($result);
	}

	public function ExistTable($table)
	{
		global $config;
		$table = $this->escapeString($table);
		$result = $this->query("select * from information_schema.tables where table_name='{$table}' and table_schema = '{$config['db_name']}'");
		return count($result);
	}

	public function ExistRecord($table, $condition)
	{
		global $config;
		$table = $this->escapeString($table);
		$result = $this->query("select * from {$table} where {$condition}");
		return count($result);
	}

	public function CreateInitTable()
	{
		if (!$this->ExistTable("user"))
		{
			$this->execute(
					"create table user(                           
					 user_id bigint unsigned primary key auto_increment,
					 user_name varchar(64) not null default 'test',
					 password varchar(64) not null default '',           
					 admin smallint unsigned not null default 0,
					 unique key(user_name),
					 key(user_id, password)
					 )engine=innodb DEFAULT charset=utf8;");             
		}
		if (!$this->ExistTable("module"))
		{
			$this->execute(
					"create table module(                           
					 id int unsigned primary key auto_increment,
					 type smallint unsigned not null default 0,             
					 main_param varchar(255) not null default '',           
					 content varchar(255) not null default ''           
					 )engine=innodb DEFAULT charset=utf8;");             
		}
		if (!$this->ExistTable("job_model"))
		{
			$this->execute(
					"create table job_model(                           
					 id int unsigned primary key auto_increment,
					 module_id int unsigned not null default 0,             
					 param varchar(255) not null default '',           
					 job_content varchar(255) not null default ''           
					 )engine=innodb DEFAULT charset=utf8;");             
		}
		if (!$this->ExistTable("job"))
		{
			/*
			 * status 0 pending 1 success 2 fail 3 running
			 */
			$this->execute(
					"create table job(                           
					 id int unsigned primary key auto_increment,
					 module_id int unsigned not null default 0,             
					 param varchar(255) not null default '',           
					 create_time int unsigned not null default 0,
					 create_user_id int unsigned not null default 0,
					 job_content varchar(255) not null default '',           
					 result text not null default '', 
					 status smallint unsigned not null default 0
					 )engine=innodb DEFAULT charset=utf8;");              
		}
	}
	
	public function GetJobList()
	{
		return $this->query("select id,job_content,param,create_time,user_name,status from job left join user on job.create_user_id = user.user_id order by create_time desc limit 100");
	}

	public function GetJobContent($id)
	{
		$id = $this->escapeString($id);
		return $this->query("select result from job where id = {$id}");
	}

	public function GetModuleByType($type)
	{
		$type = $this->escapeString($type);
		return $this->query("select id,content,main_param from module where type = {$type}");
	}

	public function GetModuleById($id)
	{
		$id = $this->escapeString($id);
		return $this->query("select id,content,main_param from module where id = {$id}");
	}

	public function GetJobModelListByModuleId($module_id)
	{
		$module_id = $this->escapeString($module_id);
		return $this->query("select id,job_content,param from job_model where module_id = {$module_id}");
	}

	public function GetJobModel($id)
	{
		$id = $this->escapeString($id);
		return $this->query("select module_id,param,job_content from job_model where id = {$id}");
	}

	public function InsertJobModel($module_id, $param, $content)
	{
		$module_id = $this->escapeString($module_id);
		$param = $this->escapeString($param);
		$content = $this->escapeString($content);
		return $this->execute("insert into job_model(module_id, param, job_content) values({$module_id},'{$param}','{$content}')");
	}

	public function InsertJob($module_id, $param, $content, $create_user_id)
	{
		$module_id = $this->escapeString($module_id);
		$param = $this->escapeString($param);
		$content = $this->escapeString($content);
		$create_user_id = $this->escapeString($create_user_id);
		return $this->execute("insert into job(module_id, param, job_content, create_time, create_user_id) values({$module_id},'{$param}','{$content}',". time(NULL) . ",'{$create_user_id}')");
	}
	
	public function GetJobbyPending($id)
	{
		return $this->query("select job.id,module_id,param,create_time,create_user_id,job_content,result,status,type,main_param from job left join module on job.module_id = module.id where status = 0 and job.id > {$id}");
	}

	public function UpdateJob($id, $status,  $result)
	{
		$id = $this->escapeString($id);
		$status = $this->escapeString($status);
		$result = $this->escapeString($result);
		return $this->execute("update job set result='{$result}', status='{$status}' where id = '{$id}'");
	}

	public function GetUserAuth($username, $password)
	{
		$usename = $this->escapeString($username);
		$password = $this->escapeString($password);

		return $this->query("select user_id,user_name,admin from user where user_name = '{$username}' and password = '{$password}'");
	}
}

?>
