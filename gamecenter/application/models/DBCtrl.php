<?php

class DBctrl extends Model {
	const AdBigShow = 1;
	const AdEditorRecommand = 2;
	const AdHotGame = 3;
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
					 is_login smallint unsigned not null default 0 comment '0:defailt no 1: need'
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

	public function GetNewGameListSortTime()
	{
		return $this->query("select game_id,icon,url,title,brief,content,create_time,onsale_time,big_pic,status,is_login from game_info where status = 3 order by onsale_time desc");
	}

	public function GetGameListByKind($mixId, $kind)
	{
		$strCondition = "";
		if (is_array($mixId))
		{
			$strCondition = "in ('" . implode(",", $mixId) . "')";
		}
		else if (is_numeric($mixId))
		{
			$strCondition = "='" . $mixId . "'"; 	
		}
		else
			return array();

		return $this->query("select game_id,icon,url,title,brief,content,create_time,onsale_time,big_pic,status,is_login from game_info where game_id " . $strCondition . " and status = " . $kind);
	}
	
	public function GetGameList($mixId)
	{
		$strCondition = "";
		if (is_array($mixId))
		{
			$strCondition = "in ('" . implode(",", $mixId) . "')";
		}
		else if (is_numeric($mixId))
		{
			$strCondition = "='" . $mixId . "'"; 	
		}
		else
			return array();

		return $this->query("select game_id,icon,url,title,brief,content,create_time,onsale_time,big_pic,status,is_login from game_info where game_id " . $strCondition);
	}

	public function GetCategoryInfoList()
	{
		return $this->query("select category_id,name,game_id_list,pic from category_info");
	}

	public function GetHotInfoList()
	{
		return $this->query("select hot_id,game_id_list,ex1,ex2,ex3 from hot_info");
	}

	public function GetHotInfoList($id)
	{
		$id = $this->escapeString($id);
		return $this->query("select hot_id,game_id_list,ex1,ex2,ex3 from hot_info where hot_id = {$id}");
	}
}

?>
