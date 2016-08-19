<?php

class DataCtrl {
	const AdBigShow = 1;
	const AdEditorRecommand = 2;
	const AdHotGame = 3;

	public function ResetAdCache()
	{
		$model = new DBCtrl;
		$model->Init();
		$cache = new RedisCtrl;
		$cache->Init();
		$category = $model->GetHotInfoList();
		$ad = array();
		foreach ($category as $key => $val)
		{
			$cacheKey = "";
			if ($val[0] == self::AdBigShow)
			{
				$cacheKey = "AdBigShow";
			}
			else if ($val[0] == self::AdEditorRecommand)
			{
				$cacheKey = "AdEditorRecommand";
			}
			else if ($val[0] ==self:: AdHotGame)
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
		$model = new DBCtrl;
		$model->Init();
		$cache = new RedisCtrl;
		$cache->Init();
		$category = $model->GetCategoryInfoList();
		$ad = array();
		$ad["Category"] = array();
		foreach ($category as $key => $val)
		{
			$ad["Category"][$val[0]] = array(
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
		$model = new DBCtrl;
		$model->Init();
		$cache = new RedisCtrl;
		$cache->Init();
		$cache->delete("NewGame");
		$category = $model->GetNewGameListSortTime();
		foreach ($category as $key => $val)
		{
			//var_dump($val[0], $val[7], "<br />");
			$cache->ZSetAdd("NewGame", $val[0], $val[7]);
		}
		return 0;
	}

	public function ResetOnSaleCache($game_id)
	{
		$model = new DBCtrl;
		$model->Init();
		$one = $model->GetGameList(intval($game_id));
		if (empty($one))
			return;
		$onsale_time = $one[0][7];
		$cache = new RedisCtrl;
		$cache->Init();
		$cache->ZSetAdd("NewGame", $game_id, $onsale_time);
	}

	public function ResetOffSaleCache($game_id)
	{
		$cache = new RedisCtrl;
		$cache->Init();
		$cache->ZSetDel("NewGame", $game_id);
		return 0;
	}

	public function ResetGameCache($game_id)
	{
		$model = new DBCtrl;
		$model->Init();
		$cache = new RedisCtrl;
		$cache->Init();
		$info = $model->GetGameList($game_id);
		if (empty($info))
		{
			return -1;
		}
		$one = $info[0];
		$info = array(
			'game_id' => $one[0],
			'icon' => $one[1],
			'url' => $one[2],
			'title' => $one[3],
			'brief' => $one[4],
			'content' => $one[5],
			'create_time' => $one[6],
			'onsale_time' => $one[7],
			'big_pic' => $one[8],
			'status' => $one[9],
			'is_login' => $one[10]
		);
		$cache->HashMSet("GameInfo", array($info['game_id'] => json_encode($info))
						);
		return 0;
	}

	public function ResetChannelCache()
	{
		$model = new DBCtrl;
		$model->Init();
		$cache = new RedisCtrl;
		$cache->Init();
		$result = $model->GetChannelInfoList();
		foreach($result as $key => $val)
		{
			$info = array(
				'channel_id' => $val[0],
				'focus_button' => $val[1]
			);
			$cache->HashMSet("ChannelInfo", array($info['channel_id'] => json_encode($info)));
		}
		return 0;
	}

	public function GetAndSetChannelInfoCache($channel_list)
	{
		$cache = new RedisCtrl;
		$cache->Init();
		$game_info = $cache->HashMGet("ChannelInfo", $channel_list);
		$game_info_nocache = array();
		foreach ($game_info as $key => $val)
		{
			if ($val != false)
			{
				$game_info[$key] = json_decode($val, true);
			}
			else
			{
				$game_info[$key] = array();
				$game_info_nocache[] = $key;
			}
		}

		if (!empty($game_info_nocache))
		{
			$model = new DBCtrl;
			$model->Init();
			$result = $model->GetChannelInfoListByChoose($game_info_nocache);
			$infoCache = array();
			foreach ($result as $key => $val)
			{
				$info = array(
					'channel_id' => $val[0],
					'focus_button' => $val[1]
				);
				$game_info[$info['channel_id']] = $info;
				$infoCache[$info['channel_id']] = json_encode($info);
			}
			//var_dump($game_info_nocache, $result);
			$cache->HashMSet("ChannelInfo", $infoCache);
		}
		return $game_info;
	}

	public function GetAndSetGameInfoCache($game_list)
	{
		$cache = new RedisCtrl;
		$cache->Init();
		$game_info = $cache->HashMGet("GameInfo", $game_list);
		$game_info_nocache = array();
		//var_dump($game_list, $game_info);
		foreach ($game_info as $key => $val)
		{
			if ($val != false)
			{
				$game_info[$key] = json_decode($val, true);
			}
			else
			{
				$game_info[$key] = array();
				$game_info_nocache[] = $key;
			}
		}

		//var_dump($game_list, $game_info, $game_info_nocache);
		if (!empty($game_info_nocache))
		{
			$model = new DBCtrl;
			$model->Init();
			$result = $model->GetGameList($game_info_nocache);
			//var_dump($result);
			$infoCache = array();
			foreach ($result as $key => $val)
			{
				$info = array(
					'game_id' => $val[0],
					'icon' => $val[1],
					'url' => $val[2],
					'title' => $val[3],
					'brief' => $val[4],
					'content' => $val[5],
					'create_time' => $val[6],
					'onsale_time' => $val[7],
					'big_pic' => $val[8],
					'status' => $val[9],
					'is_login' => $val[10]
				);
				$game_info[$info['game_id']] = $info;
				$infoCache[$info['game_id']] = json_encode($info);
			}
			//var_dump($game_info_nocache, $result);
			$cache->HashMSet("GameInfo", $infoCache);
		}
		//var_dump($game_info, $game_info_nocache);
		return $game_info;
	}

	public function HandlerGetMoreHotGame($page)
	{
		$result = array();
		$cache = new RedisCtrl;
		$cache->Init();
		$hot = $cache->StringMGet(array("AdHotGame"));
		$hot = json_decode($hot["0"], true);
		$game_list = explode(",", $hot["game_id_list"]);
		$game_list_ret = array_slice($game_list, $page * 10, 11); 
		$is_more = true;
		if (count($game_list_ret) < 11)
			$is_more = false;
		else
			array_pop($game_list_ret);
		$desc = $this->GetAndSetGameInfoCache($game_list_ret);
		$data = array();
		$data['data'] = $desc;
		$data['isMore'] = $is_more;
		return $data;
	}

	public function HandlerGetMoreNewGame($page)
	{
		$result = array();
		$cache = new RedisCtrl;
		$cache->Init();
		$new = $cache->ZSetRevRange("NewGame", $page * 10, $page * 10 + 10);
		$is_more = true;
		if (count($new) < 11)
			$is_more = false;
		else
			array_pop($new);
		$desc = $this->GetAndSetGameInfoCache($new);
		$data = array();
		$data['data'] = $desc;
		$data['isMore'] = $is_more;
		return $data;
	}

	public function HandlerGetMoreCategoryGame($page, $category_id)
	{
		$result = array();
		$cache = new RedisCtrl;
		$cache->Init();

		$ret = $cache->StringMGet(array("Category"));
		$ret = json_decode($ret[0], true);
		//var_dump($ret, $page, $category_id);
		$cate = $ret[$category_id];

		$game_list = explode(",", $cate['game_id_list']);
		$game_list_ret = array_slice($game_list, $page * 10, 11); 

		$is_more = true;
		if (count($game_list_ret) < 11)
		{
			$is_more = false;
		}
		else
			array_pop($game_list_ret);
		$desc = $this->GetAndSetGameInfoCache($game_list_ret);
		$data = array();
		$data['data'] = $desc;
		$data['isMore'] = $is_more;
		$data['name'] = $cate['name'];
		return $data;
	}

	public function HandlerGetChannelInfo($channel)
	{
		if (isset($channel))
		{
			$data = $this->GetAndSetChannelInfoCache(array($channel));
			return $data[$channel];
		}
		else
			return array();
	}


	public function HandlerGetIndex($channel)
	{
		$result = array();
		$cache = new RedisCtrl;
		$cache->Init();
		//ad
		$ad = array();
		$ret = $cache->StringMGet(array("AdBigShow", "AdEditorRecommand"));
		$ad["AdHotGame"] = json_decode($ret[0], true);
		$ad["AdEditorRecommand"] = json_decode($ret[1], true);
		//var_dump($ad);
		
		//category
		$ret = $cache->StringMGet(array("Category"));
		$ad["Category"] = json_decode($ret[0], true);

		$arr1 = explode(",", $ad["AdHotGame"]["game_id_list"]);
		$game_list = explode(",", $ad["AdEditorRecommand"]["game_id_list"]);
		$game_list_ret = array_merge($arr1, $game_list);

		$desc = $this->GetAndSetGameInfoCache($game_list_ret);
		$data = $ad;
		$data['AdGameInfo'] = $desc;
		//var_dump($data);
		
		//ad hot game list and new game list
		$data['HotGame'] = $this->HandlerGetMoreHotGame(0);
		$data['NewGame'] = $this->HandlerGetMoreNewGame(0);
		$data['ChannelInfo'] = $this->HandlerGetChannelInfo($channel);
		return $data;
	}
}

?>
