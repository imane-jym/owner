"base set
"制表符
set tabstop=4
set shiftwidth=4
set noexpandtab

"语法
syntax enable
syntax on

set number

set hlsearch

set incsearch

set ignorecase

set showcmd

"关闭兼容模式
set nocompatible

"开启文件类型侦测
filetype on
""根据侦测到的不同类型加载对应的插件
filetype plugin on
"根据侦测到的不同类型采用不同的缩进格式
filetype indent on
""取消补全内容以分割子窗口形式出现，只显示补全列表

"定义快捷键的前缀，即<Leader>
"letmapleader=";"

set encoding=utf-8 fileencoding=utf-8 fileencodings=utf-8,gb2312,ucs-bom,gb18030,cp936,big5,euc-jp,euc-kr,latin1

nmap <F11> :NERDTreeToggle<CR> :TlistToggle<CR>

"plugin set 
"pathogen set
call pathogen#infect()

"winManagerWindowLayout
let g:winManagerWindowLayout='FileExplorer|TagList'
nmap <F2> :WMToggle<cr>

"minibufexp set
let g:miniBufExplMapWindowNavVim = 1 
let g:miniBufExplMapWindowNavArrows = 1 
let g:miniBufExplMapCTabSwitchBufs = 1 
let g:miniBufExplModSelTarget = 1 

"omnicppcomplete
set completeopt=longest,menu
set nocp
map <F12> :!ctags -R --sort=yes --c++-kinds=+p --fields=+iaS --extra=+q .<CR>

imap<Leader><TAB> <C-X><C-O>
set tags+=~/.vim/bundle/omnicppcomplete-0.41/tags
"let OmniCpp_NamespaceSearch = 1
"let OmniCpp_GlobalScopeSearch = 1
"let OmniCpp_ShowAccess = 1
"let OmniCpp_ShowPrototypeInAbbr = 1 " show function parameters
"let OmniCpp_MayCompleteDot = 1 " autocomplete after .
"let OmniCpp_MayCompleteArrow = 1 " autocomplete after ->
"let OmniCpp_MayCompleteScope = 1 " autocomplete after ::
let OmniCpp_DefaultNamespaces = ["std", "_GLIBCXX_STD"]
" automatically open and close the popup menu / preview window
au CursorMovedI,InsertLeave * if pumvisible() == 0|silent! pclose|endif
set completeopt=menuone,menu,longest,preview

"TagList
let Tlist_Show_One_File = 1 "taglist插件只显示当前文件的tag
let Tlist_Use_Right_Window = 1 "让taglist窗口显示在右边，默认在左边
let Tlist_Exit_OnlyWindow = 1 "退出vim时候退出taglist
let Tlist_Auto_Open = 1 

"NERDTree
autocmd VimEnter * NERDTree                                    
autocmd TabEnter * NERDTreeMirror                              
autocmd TabEnter * wincmd p
let NERDTreeWinPos='left'  
"autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") && b:NERDTreeType == "primary") | q | endif

"protobuffer
augroup filetype                                                                                                                                                                                       
	au! BufRead,BufNewFile *.proto setfiletype proto                                                                                                                                                     
augroup end  

"vim-airline
set t_Co=256

"colorscheme solarized
let g:solarized_termcolors=256
syntax enable
if has('gui_running')
    set background=light
else
    set background=dark
endif
colorscheme solarized

"easygrep
let g:EasyGrepMode = 2 
let g:EasyGrepFilesToExclude="tags,.svn,.git,.swp,*~"
let g:EasyGrepCommand = 1
let g:EasyGrepJumpToMatch = 0

"ctrlp
let g:ctrlp_working_path_mode = 'rw'
