<?php

class CDkeyModel extends Model {
	
	public function CreateBatch($channel, $stime, $etime, $limitnumber, $batchcontent, $createtime, $author, $prize)
	{
		$batch_content = $this->escapeString($batchcontent);
		$author = $this->escapeString($author);
		$prize = $this->escapeString($prize);

		$result = $this->execute('insert into cdkey_generate_batch(channel, start_time, end_time, limit_number, batch_content, create_time, author, prize) values('. $channel . ',' . $stime .',' . $etime . ',' . $limitnumber . ",'" . $batchcontent . "'," . $createtime . ',\'' . $author . '\',\'' . $prize . '\')');
		if ($result)
		{
			$res = $this->query('SELECT LAST_INSERT_ID()');
			if ($res && count($res) != 0)
			{
				return $res[0][0];
			}
		}
		return 0;
	}

	public function InsertCDkey($cdkey, $batch_id, $createtime, $createauthor)
	{
		$cdkey = $this->escapeString($cdkey);
		$createauthor = $this->escapeString($createauthor);

		$result = $this->execute('insert into cdkey_list(cdkey, batch_id, create_time, create_author) values(\''. $cdkey . '\',' . $batch_id . ',' . $createtime . ',\'' . $createauthor . '\')');
		return $result;
	}

	public function GetCDkeyList($batch_id)
	{
		return $this->query('select cdkey,batch_id,status,channel,start_time,end_time,limit_number,batch_content from cdkey_generate_batch, cdkey_list where cdkey_list.batch_id = cdkey_generate_batch.auto_id and batch_id = ' . $batch_id);

	}
}

?>
