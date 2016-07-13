<?php
$home = $config['base_url'] . "main/index";
if (isset($channel))
	$home .= "/" . Url_helper::arrayToSegment(array('channel' => $channel));
?>
<!doctype html>
<html lang="en">

	<head>
		<meta charset="UTF-8" />
		<title>桔子游戏</title>
		<meta name="viewport" content="width=device-width, initial-scale=1, minimum-scale=1, maximum-scale=1, user-scalable=no">
		<meta http-equiv="X-UA-Compatible" content="IE=edge">
		<meta name="format-detection" content="telephone=no">
		<meta name="apple-mobile-web-app-capable" content="yes" />
		<meta name="mobile-web-app-capable" content="yes" />
		<meta name="full-screen" content="true" />
		<meta name="screen-orientation" content="portrait" />
		<meta name="x5-fullscreen" content="true" />
		<meta name="360-fullscreen" content="true" />
		<meta http-equiv="pragma" content="no-cache" />
		<meta http-equiv="cache-control" content="no-cache" />
		<meta http-equiv="cache" content="no-cache" />
		<meta http-equiv="expires" content="0" />
		<link rel="shortcut icon " href="<?php echo $config['base_url'] ?>/static/images/jvzi.ico">
		<link rel="stylesheet" type="text/css" href="<?php echo $config['base_url'] ?>/static/style/build/index.css?v=201511301259" />
<script>
var _hmt = _hmt || [];
(function() {
  var hm = document.createElement("script");
  hm.src = "//hm.baidu.com/hm.js?2e9d0558286de38654cdd2dcf234b680";
  var s = document.getElementsByTagName("script")[0]; 
  s.parentNode.insertBefore(hm, s);
})();
</script>

	</head>

	<body>
	<div id="share_logo" style="margin:0 auto;display:none;"><img src="http://cdn.11h5.com/static/image/share_logo.jpg"></div>
	<div id="home" style="margin:0 auto;display:none;" data-url="<?php echo $config['base_url'] ?>" data-enter="<?php echo $config['login_enter'] ?>" data-channel="<?php echo (isset($channel) ? $channel : ''); ?>"></div>
	<header id="head" class="base-head">
	<div class="head-menu">
		<span class="head-search"><a></a></span>
		<span class="head-icon"><a href="<?php echo $home ?>"><img src="<?php echo $config['base_url'] ?>/static/images/head-icon.png"></a></span>
		<!--<span class="head-icon"><a href="http://wx.1758.com"><img style="width: 200px;" src="http://images.1758.com/ranking/1758yearicon.png"></a></span>-->
		<!--<span class="head-dowload"><a href="http://wx.wx1758.com/game/download.htm">安装1758</a></span>-->
<?php
	if (isset($ChannelInfo['focus_button']) && $ChannelInfo['focus_button'])
	{
		echo '<a onclick="onFollowClick()" role="button" class="follow-button" data-toggle="modal" data-target="#barcodeModal"><img src="' . $config['base_url'] . '/static/images/btn-follow.png"></a>';
	}
?>
	</div>
	</header>
		<!-- <span class="count">人气：85964</span> -->
		<section class="index-tab">
			<div id='index-menu' class="pure-g index-menu">
				<div id='menu-hot' class="pure-u-1-4 dm">
					<div class="dk" data-track='hot' data-type="un">
						<a href="#hot">
							<p>热门</p>
						</a>
					</div>
				</div>
				<div id='menu-newgame' class="pure-u-1-4 dm">
					<div class="dk" data-track='newgame' data-type='un'>
						<a href="#newgame">
							<p>新游</p>
						</a>
					</div>
				</div>
				<!-- <div id='menu-gift' class="pure-u-1-4 dm">
					<div class="dk" data-track='gift' data-type='un'>
						<a href="#gift">
							<p>礼包</p>
						</a>
					</div>
				</div> -->
				<div id='menu-category' class="pure-u-1-4 dm">
					<div class="dk" data-track='category' data-type='un'>
						<a href="#category">
							<p>分类</p>
						</a>
					</div>
				</div>
			</div>
		</section>
		<section class="hot gone">
			<div class="flexslider">
				<!-- <ul class="slides">
					<li>
						<a href="http://wx.1758.com/game/wxapp/content.html?focus=0&aid=111834&ex1758=1&tp=full&title=%E6%88%91%E6%AC%B2%E5%B0%81%E5%A4%A9web&r=lb">
							<img src="http://images.1758.com/article/image/2015/10/20/21651445329561114.jpg" />
						</a>
					</li>
					<li>
						<a href="http://wx.1758.com/game/wxapp/content.html?focus=0&aid=111639&r=lb">
							<img src="http://images.1758.com/images/lbyugong.jpg" />
						</a>
					</li>
					<li>
						<a href="http://wx.1758.com/game/wxapp/content.html?focus=0&aid=111858&ex1758=1&tp=full&title=%E5%8F%AC%E5%94%A4%E5%B8%88%E5%AD%A6%E9%99%A2">
							<img src="http://images.1758.com/article/image/2015/10/23/51491445580815962.jpg" />
						</a>
					</li>
				</ul> -->
<?php
$str = '<ul class="slides">';
$arr = explode(',', $AdHotGame['game_id_list']);
$arr_pic = explode(',', $AdHotGame['ex1']);
foreach ($arr as $key => $val)
{
	$href = $config['login_enter'] . "?gameId=" . $val;
	if (isset($channel))
		$href = Url_helper::urlAddPara($href, array('channel' => $channel));
	$imeSrc = $arr_pic[$key];
	$one= <<<EOF
<li>
	<a href="$href">
		<img src="$imeSrc" />
	</a>
</li>
EOF;
	$str .= $one;
}
$str .= "</ul>";
echo $str;
?>
			</div>
			<div class="ads bg" style="display: none;">
				<div class="ads-inner">
					<div class="ads-head">
						<img src="images/notify.png" />公告
					</div>
					<div class="ads-content"></div>
				</div>
			</div>
			<div class="lib bg">
				<div class="lib-inner">
					<header class="lib-top">
						<h2>小编推荐</h2>
						<!-- <div id="new-more" class="lib-more">更多<img src="<?php echo $config['base_url'] ?>/static/images/right.png" /></div> -->
					</header>
					<div class="new-main">
						<!-- <div id="i-new-game" class="pure-g">
							<div class="pure-u-1-4">
							<a href="http://wx.1758.com/game/h5/game.htm?focus=0&aid=113062&title=%E6%88%98%E6%AD%8C&tp=full&ex1758=1"><img src="<?php echo $config['base_url'] ?>/static/game/81971465875935232.jpg"><p class="new-title">战歌</p></a>
							</div>
							<div class="pure-u-1-4">
							<a href="http://wx.1758.com/game/h5/game.htm?focus=0&aid=112884&title=%E4%B9%B1%E6%96%97%E5%B0%81%E7%A5%9E&tp=full&ex1758=1"><img src="<?php echo $config['base_url'] ?>/static/game/97741462875332028.png"><p class="new-title">乱斗封神</p></a>
							</div>
							<div class="pure-u-1-4">
							<a href="http://wx.1758.com/game/h5/game.htm?focus=0&aid=112128&title=%E6%88%98%E7%A5%9E&tp=full&ex1758=1"><img src="<?php echo $config['base_url'] ?>/static/game/58771456811646037.png"><p class="new-title">战神</p></a>
							</div>
						</div> -->
<?php
$str = '<div id="i-new-game" class="pure-g">';
$arr = explode(',', $AdEditorRecommand['game_id_list']);
foreach ($arr as $key => $val)
{
	$href = $config['login_enter'] . "?gameId=" . $val;
	if (isset($channel))
		$href = Url_helper::urlAddPara($href, array('channel' => $channel));
	$imgSrc = $AdGameInfo[$val]['icon'];
	$name = $AdGameInfo[$val]['title'];
	$one= <<<EOF
							<div class="pure-u-1-4">
							<a href="$href"><img src="$imgSrc"><p class="new-title">$name</p></a>
							</div>
EOF;
	$str .= $one;
}
$str .= "</div>";
echo $str;
?>
					</div>
				</div>
			</div>
			<div class="lib bg">
				<div class="lib-inner">
					<header class="lib-top">
						<h2>热门游戏</h2>
						<!--<div class="lib-more">更多<img src="images/right.png"/></div>-->
					</header>
					<div id="hot-game" class="list hot-main">
						<!-- <div class="item">
							<a class="i-info" href="http://wx.1758.com/game/h5/game.htm?focus=0&aid=112815&title=%E5%8F%A3%E8%A2%8B%E5%A6%96%E6%80%AA%E8%81%94%E7%9B%9F&tp=full&ex1758=1">
							<figure class="cover"><img src="<?php echo $config['base_url'] ?>/static/game/87311463556210206.png"></figure>
								<div class="meta"><h3 class="title">口袋妖怪联盟<span class="identification">礼包</span></h3>
								<div class="desc">经典动漫，全自动挂机，激情无限。</div>
								</div>
							</a>
							<a href="http://w.g1758.cn/kdyglm/index.html?tp=fs&ex1758=1&title=%E5%8F%A3%E8%A2%8B%E5%A6%96%E6%80%AA%E8%81%94%E7%9B%9F">
								<div class="play-btn"><i class="icon-right"></i>开始</div>
                            </a>
                        </div> -->
<?php
$str = '<div id="hot-game-list">';
foreach ($HotGame['data'] as $key => $val)
{
	$href = $config['login_enter'] . "?gameId=" . $key;
	if (isset($channel))
		$href = Url_helper::urlAddPara($href, array('channel' => $channel));
	$imgSrc = $val['icon'];
	$name = $val['title'];
	$brief = $val['brief'];
	$one= <<<EOF
						<div class="item">
							<a class="i-info" href="$href">
							<figure class="cover"><img src="$imgSrc"></figure>
								<div class="meta"><h3 class="title">$name</h3>
								<div class="desc">$brief</div>
								</div>
							</a>
							<a href="$href">
								<div class="play-btn"><i class="icon-right"></i>开始</div>
                            </a>
                        </div>
EOF;
	$str .= $one;
}
$str .= '</div>';
echo $str;
?>
						<div class="more-info" data-num="1" data-track='hot'>
							<a>点击加载更多</a>
						</div>
					</div>
				</div>
			</div>
		</section>
		<section id="newgames" class="newgame bg list gone">
		    <!-- <div class="item"><a class="i-info" href="http://wx.1758.com/game/h5/game.htm?focus=0&aid=113078&title=%E6%90%9C%E7%A5%9E%E8%AE%B0&tp=full&ex1758=1"><figure class="cover"><img src="./1758hot_files/91681465194588397.gif"></figure><div class="meta"><h3 class="title">搜神记</h3><div class="desc">手握神兵美女在怀，搜神记等你来战！</div></div></a><a href="http://w.g1758.cn/soushenji/index.html?tp=fs&ex1758=1&title=%E6%90%9C%E7%A5%9E%E8%AE%B0"><div class="play-btn"><i class="icon-right"></i>开始</div></a></div> -->
<?php
$str = '<div id="new-game">';
foreach ($NewGame['data'] as $key => $val)
{
	$href = $config['login_enter'] . "?gameId=" . $key;
	if (isset($channel))
		$href = Url_helper::urlAddPara($href, array('channel' => $channel));
	$imgSrc = $val['icon'];
	$name = $val['title'];
	$brief = $val['brief'];
	$one= <<<EOF
		    <div class="item"><a class="i-info" href="$href"><figure class="cover"><img src="$imgSrc"></figure><div class="meta"><h3 class="title">$name</h3><div class="desc">$brief</div></div></a><a href="$href"><div class="play-btn"><i class="icon-right"></i>开始</div></a></div>
EOF;
	$str .= $one;
}
$str .= '</div>';
echo $str;
?>
			<div class="more-info" data-num="1" data-track='newgame'><a>点击加载更多</a></div>
		</section>
		<!-- <section class="gift bg gone">
			<div id="gift-list" class="gift-list list">
				<div class="item">
				    <a class="i-info" href="http://wx.1758.com/game/h5/giftinfo.htm?aid=113148&tp=full&ex1758=1&title=%E9%A2%86%E5%8F%96%E7%A4%BC%E5%8C%85">
				        <figure class="cover"><img src="./1758hot_files/69411464143423940.png"></figure>
				        <div class="meta"><h3 class="title">暗黑之王:1758父亲节礼包(1-4000)</h3><span class="g-fail">开放时间   </span>&nbsp;<span class="g-fail-day">今日  17:58</span> </div></a><a class="notime-btn" data-num="113148" data-value="0" data-time="1465898280000">未开放
				    </a>
				</div>
				<div class="more-info" data-num="1" data-track='gift'><a>点击加载更多</a></div>
			</div>
		</section> -->
		<section class="category gone">
			<!-- <div class="c-search">
				<form id="form" class="form" action="http://wx.1758.com/game/wxgame/search.html" name="f">
					<div class="con-wrap">
						<div class="f-ser">
							<input id="keyword" name="keyword" type="text" placeholder="请输入游戏名" />
							<input name="tp" type="hidden" value="full" />
							<input name="ex1758" type="hidden" value="1" />
							<input name="title" type="hidden" value="搜索结果" />
						</div>
						<div class="f-btn">
							<button id="su" type="submit" class="pure-button">搜&nbsp;索</button>
						</div>
					</div>
				</form>
			</div> -->
			<div id="c-list" class="c-list">
				<!-- <ul class="pure-g">
                    <li class="pure-u-1-2">
                        <div><a href="http://wx.1758.com/game/h5/page/singlegamelist.htm?cid=111&ex1758=1&tp=full&yn=%E7%82%B9%E5%87%BB%E6%B8%B8%E6%88%8F&title=%E7%82%B9%E5%87%BB%E6%B8%B8%E6%88%8F"><img src="./1758hot_files/82651465210403601.jpg" width="100%"><div class="title"><div class="t">点击游戏</div><div class="n">43款</div></div></a>
                        </div>
                    </li>
				</ul> -->
<?php
$str = '<ul class="pure-g">';
foreach ($Category as $key => $val)
{
	$arr = explode(',', $val['game_id_list']);
	$href = $config['base_url'] . "category/index";
	if (isset($channel))
		$href .= "/" . Url_helper::arrayToSegment(array('channel' => $channel, 'category_id' => $key));
	else 
		$href .= "/" . Url_helper::arrayToSegment(array('category_id' => $key));
	$imgSrc = $val['pic'];
	$name = $val['name'];
	$cnt = count($arr);
	$one= <<<EOF
                    <li class="pure-u-1-2">
                        <div><a href="$href"><img src="$imgSrc" width="100%"><div class="title"><div class="t">$name</div><div class="n">$cnt 款</div></div></a>
                        </div>
                    </li>
EOF;
	$str .= $one;
}
$str .= "</ul>";
echo $str;
?>
			</div>
		</section>
		<div class="tip gone">
			<div class="tip-dialog">
				<div class="tip-wrapper">
					<div class="tip-content tip-exclusive">
						<div class="tip-body">
							<p class="ex-con"><span style="color: #71A540;">专属礼包</span>需通过桔子游戏客户端领取</p>
							<span class="ex-inner">
							<span class="ex-info">您还没有安装桔子游戏客户端？</span>
							<a class="ex-load" href="http://m.1758.com/game/download.htm">立即下载</a>
							</span>
						</div>
					</div>
				</div>
			</div>
		</div>
		<!--<script src="js/require-2.1.20.min.js" data-main="js/build/index.js?v=201601141949"></script>-->
		<!--<script src="js/require-2.1.20.min.js" data-main="dist/index/js/index_0_1.js?v=201604201713"></script>-->
		<!-- <audio controls="controls" style="display: none;"></audio>
		<section id="base-footer-game" class="base-footer">
        	<div id="base-menu" class="pure-g base-menu">
        	    <div class="pure-u-1-3 cursor">
        	    	<a>
        	    		<img src="./1758hot_files/wyxy.png">
        	    	</a>
        	    </div>
        	    <div class="pure-u-1-3">
        	    	<a href="http://wx.1758.com/game/h5/newsfeed.htm">
        	    		<img src="./1758hot_files/wsqw.png">
        	    	</a>
        	    </div>
        	    <div class="pure-u-1-3">
        	    	<a href="http://wx.1758.com/game/h5/user.htm">
        	    		<img src="./1758hot_files/wdw.png">
        	    	</a>
        	    </div>
        	</div>
        </section> -->
        <div class="modal-backdrop fade in" style="display: none"></div>
                <div class="modal-backdrop-trans modal-dialog" role="document" style="display: none">
                    <div class="modal-content">
                        <div class="modal-header">
                            <h4 class="modal-title" id="barcodeModalLabel">关注“桔子游戏”</h4>
                        </div>
                        <div class="modal-body">
                            <img class="qrcode" src="<?php echo $config['base_url'] ?>/static/images/mp-qrcode.jpg">
                        </div>
                        <div class="modal-footer">
                            <h4 class="modal-title">长按识别二维码</h4>
                        </div>
                    </div>
                </div>
	</body>

<script src="http://libs.baidu.com/jquery/1.9.1/jquery.min.js"></script>
<script src="http://cdn.bootcss.com/flexslider/2.6.1/jquery.flexslider-min.js"></script>
<script src="<?php echo $config['base_url'] ?>/static/js/sys.js"></script>
</html>
