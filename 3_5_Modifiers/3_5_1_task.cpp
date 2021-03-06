/*

Определен следующий класс (он также приведен в комментарии в шаблоне кода):

struct Cls {
    Cls(char c, double d, int i);
private:
    char c;
    double d;
    int i;
};
Как видно, все поля этого класса закрытые, ваша задача реализовать несколько функций, 
которые дают полный доступ к этим полям (см. шаблон кода), несмотря на то, что они закрытые.

Внимание: предполагаемое решение этого задания существенно опирается на Undefined Behaviour 
и является исключительно учебным, но полезно для лучшего понимания того, как работают модификаторы доступа. Решение было проверено на различных компиляторах (g++/clang++/icc/msvc), 
но мы настоятельно не рекомендуем использовать подобные трюки в боевом коде.

*/

struct ClsPublic {
ClsPublic(char _c, double _d, int _i);
public: 
	char c;
	double d;
	int i;
};

char &get_c(Cls &cls) {
	void* voidptr = static_cast<void*>(&cls);
	struct ClsPublic * p = static_cast<ClsPublic*>(voidptr); 
	return p->c; 
}

double &get_d(Cls &cls) {
	void* voidptr = static_cast<void*>(&cls); 
	struct ClsPublic * p = static_cast<ClsPublic*>(voidptr); 
	return p->d; 
}

int &get_i(Cls &cls) {
	void* voidptr = static_cast<void*>(&cls);
	struct ClsPublic * p = static_cast<ClsPublic*>(voidptr);
	return p->i;
}
