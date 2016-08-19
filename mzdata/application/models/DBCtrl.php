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
	
	public function GetUserAll($maxId)
	{
		return $this->query("select role_id,name,gm_auth,status,progress,level,gold,diamond,cur_stage,cur_train,vip_level,vip_exp,stamina,energy,quest,last_login_time,diamond_pay from player_info where role_id in (select re.role_id from passport_info as info, re_passport_player as re where info.passport_id = re.passport_id and re.role_id > {$maxId}) limit 100");
	}

	public function GetUserFirst($t)
	{
		return $this->query("select role_id,name,gm_auth,status,progress,level,gold,diamond,cur_stage,cur_train,vip_level,vip_exp,stamina,energy,quest,last_login_time,diamond_pay from player_info where role_id in (select re.role_id from passport_info as info, re_passport_player as re where info.passport_id = re.passport_id and re.create_time > {$t}) limit 100");
	}
}

?>
