// Приведенный ниже блок ifdef — это стандартный метод создания макросов, упрощающий процедуру
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа LIBNMCANWRAPPER_EXPORTS
// Символ, определенный в командной строке. Этот символ не должен быть определен в каком-либо проекте,
// использующем данную DLL. Благодаря этому любой другой проект, исходные файлы которого включают данный файл, видит
// функции LIBNMCANWRAPPER_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
#ifdef LIBNMCANWRAPPER_EXPORTS
#define LIBNMCANWRAPPER_API __declspec(dllexport)
#else
#define LIBNMCANWRAPPER_API __declspec(dllimport)
#endif

// Этот класс экспортирован из библиотеки DLL
class LIBNMCANWRAPPER_API Clibnmcanwrapper {
public:
	Clibnmcanwrapper(void);
	// TODO: добавьте сюда свои методы.
};

extern LIBNMCANWRAPPER_API int nlibnmcanwrapper;

LIBNMCANWRAPPER_API int fnlibnmcanwrapper(void);
