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
	</head>

	<body>
	<div id="share_logo" style="margin:0 auto;display:none;"><img src="http://cdn.11h5.com/static/image/share_logo.jpg"></div>
	<div id="home" style="margin:0 auto;display:none;" data-url="<?php echo $config['base_url'] ?>" data-channel="<?php echo isset($channel) ? $channel : ''; ?>" data-category-id="<?php echo $CategoryId ?>" data-enter="<?php echo $config['login_enter'] ?>"></div>
	<header id="head" class="base-head">
	<div class="head-menu">
		<span class="head-search"><a></a></span>
		<span class="head-icon"><a href="<?php echo $home ?>"><img src="<?php echo $config['base_url'] ?>/static/images/head-icon.png"></a></span>
		<!--<span class="head-icon"><a href="http://wx.1758.com"><img style="width: 200px;" src="http://images.1758.com/ranking/1758yearicon.png"></a></span>-->
		<!--<span class="head-dowload"><a href="http://wx.wx1758.com/game/download.htm">安装1758</a></span>-->
		<!-- <a onclick="onFollowClick()" role="button" class="follow-button" data-toggle="modal" data-target="#barcodeModal"><img src="<?php echo $config['base_url'] ?>/static/images/btn-follow.png"></a> -->
	</div>
	</header>
		<!-- <span class="count">人气：85964</span> -->
		<section class="index-tab" style="margin:0 auto;display:none;">
			<div id='index-menu' class="pure-g index-menu">
				<div id='menu-hot' class="pure-u-1-4 dm">
					<div class="dk" data-track='hot' data-type="un">
						<a href="#hot">
							<p>热门</p>
						</a>
					</div>
				</div>
			</div>
		</section>
		<section class="hot gone">
			<div class="lib bg">
				<div class="lib-inner">
					<header class="lib-top">
						<h2><?php echo $Category['name'] ?></h2>
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
$str = '<div id="category-game-list">';
foreach ($Category['data'] as $key => $val)
{
	$href = $config['login_enter'] . "?gameId=" . $val['game_id'];
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
						<div class="more-info" data-num="1" data-track='category'>
							<a>点击加载更多</a>
						</div>
					</div>
				</div>
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
