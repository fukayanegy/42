# get_next_line  
42cursusの二つ目の課題
## get_next_line algorithm
1. 一番はじめにopenされているファイルを全て読み込みこむ
2. 読み込んだ文章をstatic char *型の変数に格納する
3. 最後にft_search_newlineを使用して改行までを返す
## my function
utils に入っている関数についての説明
### ft_strlen
引数の文字列の長さを返す
### ft_skip_newline
char *sを引数として、その引数に改行か終端文字があったらそれ以降をコピーして返す
### ft_search_newline
char *sを引数として、その引数に改行か終端文字があったらそこまでをコピーして返す
### ft_strjoin
char *型二つを引数にとって、それらを結合した文字列を返す
