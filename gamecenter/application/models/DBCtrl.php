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
		if (!$this->ExistTable("game_info"))
		{
			$this->execute(
					"create table game_info(                           
					 game_id int unsigned primary key auto_increment,
					 icon varchar(255) not null default '',           
					 url varchar(255) not null default '',           
					 title varchar(255) not null default '',           
					 brief varchar(255) not null default '',           
					 content varchar(65535) not null default '',           
					 create_time int unsigned not null default 0,
					 onsale_time int unsigned not null default 0,
					 big_pic varchar(255) not null default '',           
					 status smallint unsigned not null default 0 comment '0:defailt no pass 1: pass 2: test 3: onsale 4: offsale'
					 )engine=innodb DEFAULT charset=utf8;");              
		}
		if (!$this->ExistTable("category_info"))
		{
			$this->execute(
					"create table category_info(                           
					 category_id int unsigned primary key auto_increment,
					 name varchar(255) not null default '',           
					 game_id_list varchar(65535) not null default '',           
					 pic varchar(255) not null default '',           
					 )engine=innodb DEFAULT charset=utf8;");              
		}
		if (!$this->ExistTable("hot_info"))
		{
			$this->execute(
					"create table category_info(                           
					 hot_id int unsigned primary key auto_increment,
					 game_id_list varchar(65535) not null default '',           
					 ex1 varchar(65535) not null default '',           
					 ex2 varchar(65535) not null default '',           
					 ex3 varchar(65535) not null default '',           
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
