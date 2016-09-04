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
					 content varchar(20000) not null default '',           
					 create_time int unsigned not null default 0,
					 onsale_time int unsigned not null default 0,
					 big_pic varchar(255) not null default '',           
					 status smallint unsigned not null default 0 comment '0:defailt no pass 1: pass 2: test 3: onsale 4: offsale',
					 is_login smallint unsigned not null default 0 comment '0:defailt no 1: need'
					 )engine=innodb DEFAULT charset=utf8;");              
		}
		if (!$this->ExistTable("category_info"))
		{
			$this->execute(
					"create table category_info(                           
					 category_id int unsigned primary key auto_increment,
					 name varchar(255) not null default '',           
					 game_id_list TEXT not null default '',           
					 pic varchar(255) not null default ''           
					 )engine=innodb DEFAULT charset=utf8;");              
		}
		if (!$this->ExistTable("hot_info"))
		{
			$this->execute(
					"create table hot_info(                           
					 hot_id int unsigned primary key auto_increment,
					 game_id_list varchar(5000) not null default '',           
					 ex1 varchar(5000) not null default '',           
					 ex2 varchar(5000) not null default '',           
					 ex3 varchar(5000) not null default ''
					 )engine=innodb DEFAULT charset=utf8;");              
		}
		if (!$this->ExistTable("channel_info"))
		{
			$this->execute(
					"create table channel_info(                           
					 channel_id int unsigned primary key auto_increment,
					 focus_button smallint unsigned not null default 1 comment '0:defailt hidden 1: show',
					 content varchar(5000) not null default ''           
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
			$strCondition = "in (" . implode(",", $mixId) . ")";
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

	public function GetHotInfo($id)
	{
		$id = $this->escapeString($id);
		return $this->query("select hot_id,game_id_list,ex1,ex2,ex3 from hot_info where hot_id = {$id}");
	}

	public function GetChannelInfo($id)
	{
		$id = $this->escapeString($id);
		return $this->query("select channel_id,focus_button from channel_info where channel_id = {$id}");
	}

	public function GetChannelInfoList()
	{
		return $this->query("select channel_id,focus_button from channel_info");
	}

	public function GetChannelInfoListByChoose($mixId)
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

		return $this->query("select channel_id,focus_button from channel_info where channel_id " . $strCondition);
	}

	public function UpsertGameInfo($game)
	{
		$game_id = $this->escapeString($game['game_id']);
		$icon = $this->escapeString($game['icon']);
		$url = $this->escapeString($game['url']);
		$title = $this->escapeString($game['title']);
		$brief = $this->escapeString($game['brief']);
		$content = $this->escapeString($game['content']);
		$create_time = $this->escapeString($game['create_time']);
		$onsale_time = $this->escapeString($game['onsale_time']);
		$big_pic = $this->escapeString($game['big_pic']);
		$status = $this->escapeString($game['status']);
		$is_login = $this->escapeString($game['is_login']);
		$str = "insert into game_info(game_id, icon, url, title, brief, content, create_time, onsale_time, big_pic, status, is_login) values({$game_id}, '{$icon}', '{$url}', '{$title}', '{$brief}', '{$content}', {$create_time}, {$onsale_time}, '{$big_pic}', {$game['status']}, '{$game['is_login']}') ON DUPLICATE KEY UPDATE icon = '{$icon}', url = '{$url}', title = '{$title}', brief = '{$brief}', content = '{$content}', create_time = {$create_time}, onsale_time = {$onsale_time}, big_pic = '{$big_pic}', status = {$status}, is_login = '{$is_login}'";
		return $this->execute($str);
	}

	public function UpsertCategoryInfo($info)
	{
		$category_id = $this->escapeString($info['category_id']);
		$name = $this->escapeString($info['name']);
		$game_id_list = $this->escapeString($info['game_id_list']);
		$pic = $this->escapeString($info['pic']);
		$str = "insert into category_info(category_id, name, game_id_list, pic) values({$category_id}, '{$name}', '{$game_id_list}', '{$pic}') ON DUPLICATE KEY UPDATE name = '{$name}', game_id_list = '{$game_id_list}', pic = '{$pic}'";
		return $this->execute($str);
	}

	public function UpsertAdInfo($info)
	{
		$hot_id = $this->escapeString($info['hot_id']);
		$game_id_list = $this->escapeString($info['game_id_list']);
		$ex1 = $this->escapeString($info['ex1']);
		$ex2 = $this->escapeString($info['ex2']);
		$ex3 = $this->escapeString($info['ex3']);
		$str = "insert into hot_info(hot_id, game_id_list, ex1, ex2, ex3) values({$hot_id}, '{$game_id_list}', '{$ex1}', '{$ex2}', '{$ex3}') ON DUPLICATE KEY UPDATE game_id_list = '{$game_id_list}', ex1 = '{$ex1}', ex2 = '{$ex2}', ex3 = '{$ex3}'";
		return $this->execute($str);
	}

	public function UpsertChannelInfo($info)
	{
		$channel_id = $this->escapeString($info['channel_id']);
		$content = $this->escapeString($info['content']);
		$str = "insert into channel_info(channel_id, focus_button, content) values({$channel_id}, '{$focus_button}', '{$content}') ON DUPLICATE KEY UPDATE focus_button = '{$focus_button}', content = '{$content}'";
		return $this->execute($str);
	}
}

?>
