# get_next_line  
42cursusの二つ目の課題  
## get_next_line algorithm  
1. 一番はじめにopenされているファイルを全て読み込みこむ  
1. 読み込んだ文章をstatic char *型の変数に格納する  
1. 最後にft_search_newlineを使用して改行までを返す  
## get_next_line algorithm retry(1)  
1. はじめにbuffasize分だけreadを行う この際の格納先はchar *型のtemporary_read_data  
1. temporary_read_dataをstatic char *型の変数read_dataとstrjoin()を用いて結合する  
1. read_dataの中に改行文字が含まれていれば1に戻る, 含まれていなければ4に進む, read_sizeが0だった場合,   
1. copy_before(read_data)の戻り値をchar *型のresに格納する  
1. read_data = copy_after(read_data) を行い、出力する以外の文字列を削除する  
1. resを返す  
## get_next_line algorithm retry(2)  
1. 変数として以下のものを定義する  
	1. char			*temporary_read_data  
	1. char			*result;  
	1. static char	*read_data;  
	1. ssize_t		read_size;  
	1. int			checker;  
1. malloc で result, temporary_read_data のメモリーを確保する  
この際にNULLが返ってきたらreturn (NULL)を返す  
1. while (read_dataに'\n'が含まれていない限り回す)  
	1. read で temporary_read_data にサイズ分入れる  
		read の返り値が-1であれば,checker を-1にする(error であるため最終的にNULLを返す必要がある)  
		read の返り値が0であれば, checker を0にして返す(指定ファイルの最終文字まで読み込んだため終了する必要がある)  
		read の返り値が1以上であれば, checker を1にして返す(指定ファイルが余っている状態で'\n'が現れた場合の処理)  
	1. 読み込んだデータに終端文字を加える(temporary_read_data[read_size] = '\0')  
	1. 読み込んだ一時データをread_dataに加える(read_data = ft_strjoin(read_data, temporary_read_data))  
	1.   
1. checkerによって処理が変わる  
	1. checker = -1 の場合  
		フリー処理を行いreturn (NULL)を返す  
	1. checker = 0 の場合  
		フリー処理を行いreturn (NULL)を返す  
	1. checker = 1 の場合  
		result = ft_copy_newline_before(read_data);  
		read_data = ft_copy_newline_after(read_data);  
1. free処理を入れる  
1. return (result);  
## my function  
utils に入っている関数についての説明  
### ft_strlen(const char *s)  
引数の文字列の長さを返す  
### ft_copy_before_newline(const char *s)  
const char *sを引数として、その引数に改行か終端文字があったらそこまでをコピーして返す  
この際に改行が含まれていなかった場合、sをそのまま返す  
### ft_copy_after_newline(const char *s)  
const char *sを引数として、その引数に改行か終端文字があったらそれ以降をコピーして返す  
この際に改行が含まれていなかった場合、NULLを返す  
### ft_exist_newline(const char *s)  
sの中に'\n'が含まれていればtrue, 含まれていなければfalseを返す  
### ft_strjoin(const char *s1, const char *s2)  
char *型二つを引数にとって、それらを結合した文字列を返す  

## 使えそうなリンク
1. [tester](https://github.com/Tripouille/gnlTester.git)
2. [メモリリークの確認](https://qiita.com/ryo_manba/items/0ecffc15ead63e4900e8)
