<?php

class DataCtrl {
	const AdBigShow = 1;
	const AdEditorRecommand = 2;
	const AdHotGame = 3;

	public function ResetAdCache()
	{
		global $config;
		if (!isset($_REQUEST['token']))
		{
			return -1;
		}
		if ($_REQUEST['token'] != $config['secure_key'])
		{
			return -1;
		}
		$model = new DBCtrl;
		$model->Init();
		$cache = new RedisCtrl;
		$cache->Init();
		$category = $model->GetHotInfoList();
		$ad = array();
		foreach ($category as $key => $val)
		{
			$cacheKey = "";
			if ($val[0] == AdBigShow)
			{
				$cacheKey = "AdBigShow";
			}
			else if ($val[0] == AdEditorRecommand)
			{
				$cacheKey = "AdEditorRecommand";
			}
			else if ($val[0] == AdHotGame)
			{
				$cacheKey = "AdHotGame";
			}
			else
			{
				continue;
			}
			$ad[$cacheKey] = json_encode(array(
				"hot_id" => $val[0],
				"game_id_list" => $val[1],
				"ex1" => $val[2],
				"ex2" => $val[3],
				"ex3" => $val[4]
			));
		}
		$cache->StringMSet($ad);
		return 0;
	}

	public function ResetCategoryCache()
	{
		global $config;
		if (!isset($_REQUEST['token']))
		{
			return -1;
		}
		if ($_REQUEST['token'] != $config['secure_key'])
		{
			return -1;
		}
		$model = new DBCtrl;
		$model->Init();
		$cache = new RedisCtrl;
		$cache->Init();
		$category = $model->GetCategoryInfoList();
		$ad = array();
		$ad["Category"] = array();
		foreach ($category as $key => $val)
		{
			$ad["Category"][] = array(
				"category_id" => $val[0],
				"name" => $val[1],
				"game_id_list" => $val[2],
				"pic" => $val[3]
			);
		}
		$ad["Category"] = json_encode($ad["Category"]);
		$cache->StringMSet($ad);
		return 0;
	}

	public function ResetNewGameCache()
	{
		global $config;
		if (!isset($_REQUEST['token']))
		{
			return -1;
		}
		if ($_REQUEST['token'] != $config['secure_key'])
		{
			return -1;
		}
		$model = new DBCtrl;
		$model->Init();
		$cache = new RedisCtrl;
		$cache->Init();
		$cache->delete("NewGame");
		$category = $model->GetNewGameListSortTime();
		foreach ($category as $key => $val)
		{
			$cache->ZSetAdd("NewGame", $val[0], $val[7]);
		}
		return 0;
	}

	public function GetAndSetGameInfoCache($game_id)
	{
		$model = new DBCtrl;
		$model->Init();
		$cache = new RedisCtrl;
		$cache->Init();
		$info = $model->GetGameList($game_id);
		if (empty($info))
		{
			return Array();
		}
		$info = array(
			'game_id' => $info[0],
			'icon' => $info[1],
			'url' => $info[2],
			'title' => $info[3],
			'brief' => $info[4],
			'content' => $info[5],
			'create_time' => $info[6],
			'onsale_time' => $info[7],
			'big_pic' => $info[8],
			'status' => $info[9],
			'is_login' => $info[10]
		);
		$cache->HashMSet("GameInfo", array($category[0], json_encode($info))
						);
		return $info;
	}

	public function ResetOnSaleCache($game_id, $onsale_time)
	{
		global $config;
		if (!isset($_REQUEST['token']))
		{
			return -1;
		}
		if ($_REQUEST['token'] != $config['secure_key'])
		{
			return -1;
		}
		$cache = new RedisCtrl;
		$cache->Init();
		$cache->ZSetAdd("NewGame", $game_id, $onsale_time);
	}

	public function ResetOffSaleCache($game_id)
	{
		global $config;
		if (!isset($_REQUEST['token']))
		{
			return -1;
		}
		if ($_REQUEST['token'] != $config['secure_key'])
		{
			return -1;
		}
		$cache = new RedisCtrl;
		$cache->Init();
		$cache->ZSetDel("NewGame", $game_id);
		return 0;
	}

	public function HandlerGetMoreHotGame()
	{
		$result = array();
		if (!isset($_REQUEST['page']))
		{
			return $result;
		}
		$cache = new RedisCtrl;
		$cache->Init();
		$cache->ZSetDel("NewGame", $game_id);
	}
}

?>
