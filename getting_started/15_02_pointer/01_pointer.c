// 関数から情報を返す方法
// 戻り値を使う方法 → 1つの情報しか返すことができない

// 2つ以上の情報を返すために、ポインタ型の引数を使って情報を返す

// C言語では、関数へ情報を渡す場合、必ず元の変数の値のコピーを渡す
// = 値渡し
// 値渡しとは
// 引数の渡しかた
// 元の変数の値が変更されないことが特徴

// 値渡しと参照渡しの違い
// https://magazine.rubyist.net/articles/0032/0032-CallByValueAndCallByReference.html#:~:text=%E3%80%8C%E5%80%A4%E6%B8%A1%E3%81%97%E3%80%8D%E3%81%A8%E3%80%8C%E5%8F%82%E7%85%A7,%E3%82%88%E3%81%86%E3%81%AA%E6%B8%A1%E3%81%97%E6%96%B9%E3%81%A7%E3%81%99%E3%80%82
// >「値渡し (call by value)」とは、変数の値をコピーする渡し方です。
// >「参照渡し (call by reference)」とは、変数を共有するような渡し方です。

// 変数の実体は、メモリ上に確保された領域
// Ruby
// 変数xとyを宣言する
// x = 10
// y = 20
// 変数 x はメモリ番地 (例)0x8840 上の領域であり、値として数値の「10」が格納されている
// 変数 y はメモリ番地 (例)0x8844 上の領域であり、値として数値の「20」が格納されている

// 引数を 2 つ持つ関数を定義する
// def foo(a, b)
//   a += 1
//   b += 2
// end
// このとき、関数fooで使われている引数a, bはどちらも、メモリ上に領域が確保される
// この領域は固定された場所ではなく、関数が呼ばれると確保され、関数の実行が終了すると開放される

// 値渡し (call by value) とは、
// 変数の値をコピーする渡し方で、Ruby も値渡しです。 
// 変数 x と y を指定して関数 foo() を呼び出しています。
// def foo(a, b)     # a, b を「仮引数」という
//   a += 1
//   b += 2          # a と b を変更する
// end

// x = 10
// y = 20
// foo(x, y)         # x, y を「実引数」という
// puts x            #=> 10  # 変更されてない
// puts y            #=> 20  # 変更されてない

// 値渡しでは実引数/変数 x と y の値が、仮引数/引数 a と b にコピーされる
// このとき、a と b の値は変更されますが、それは x と y には反映されない
// 仮引数を変更しても、それが実引数には反映されない。

// 参照渡し
// 変数のメモリ番地を渡す渡し方
// あたかも変数が共有されたような状態になる

// もし Ruby が参照渡しだったとした場合
// def foo(a, b)     # a, b を「仮引数」という
//   a += 1
//   b += 2          # a と b を変更する
// end

// x = 10
// y = 20
// foo(x, y)         # x, y を「実引数」という
// puts x            #=> 11   # 変更されている!
// puts y            #=> 22   # 変更されている!

// 参照渡しでは、変数のメモリアドレスが実引数x, yに渡される
// a や b を操作すると、x と y の値が変わる

// ===========

// ポインタ型の引数を使って情報を返す例
#include <stdio.h>

// プロトタイプ宣言
// 関数等のプロシージャをソースコードの冒頭部分で宣言して後で定義すること
void func(int* pvalue);

int main(void)
{
    int value = 10;
    // 出力① valueのメモリアドレス
    printf("&value = %p\n", &value);
    // 関数func()にint型の変数valueのメモリアドレスを渡す
    func(&value);
    // 出力③ valueの値 = func()の実行により、100が代入されている
    printf("value = %d\n", value);
    return 0;
}

// 関数func()の定義
// 引数としてポインタ変数pvalueを受け取る
void func(int *pvalue)
{
    // 出力② ポインタ変数pvalueの値 = &value
    printf("pvalue = %p\n", pvalue);
    // 通常変数モードに切り替えて代入
    *pvalue = 100;
    return;
}

// ➜  15_02_pointer git:(main) ✗ gcc -o 01_pointer 01_pointer.c && ./01_pointer
// &value = 0x16b9470a8
// pvalue = 0x16b9470a8
// value = 100