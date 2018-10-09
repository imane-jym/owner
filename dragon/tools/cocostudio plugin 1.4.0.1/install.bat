@echo off
set custom_widget_path=C:\Users\%username%\Documents\CocoStudio\Plugins\1.4
echo %custom_widget_path%

set plugin1_name=CustomWidget.dll
set plugin2_name=CustomWidgetWrap.dll
set src_plugin1_path=%cd%\plugin\%plugin1_name%
set src_plugin2_path=%cd%\plugin\%plugin2_name%
set des_plugin1_path=%custom_widget_path%\%plugin1_name%
set des_plugin2_path=%custom_widget_path%\%plugin2_name%

if exist %src_plugin1_path% (
echo F | xcopy /e /y %src_plugin1_path% %des_plugin1_path%
) else (
echo file don't exist.%src_plugin1_path%
)

if exist %src_plugin2_path% (
echo F | xcopy /e /y %src_plugin2_path% %des_plugin2_path%
) else (
echo file don't exist.%src_plugin1_path%
)

echo %src_plugin1_path%
echo %src_plugin2_path%
echo %des_plugin1_path%
echo %des_plugin2_path%

pause
