#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>
#include <algorithm>
using namespace std;
map<string, string> parseArguments(int argc, char* argv[])
{
    map<string, string> params;
    for (int i = 1; i < argc; i += 2)
    {
        if (i + 1 < argc)
        {
            string key = argv[i];
            string value = argv[i + 1];
            params[key] = value;
        }
    }
    return params;
}
void printParameters(const map<string, string>& params)
{
    cout << "=== Параметры конфигурации ===\n";
    for (const auto& pair : params)
    {
        cout << pair.first << ": " << pair.second << "\n";
    }
    cout << "==============================\n";
}
bool validateParameters(const map<string, string>& params)
{
    vector<string> required = { "--package", "--repo", "--test-mode", "--version", "--filter" };
    for (const auto& key : required)
    {
        if (params.find(key) == params.end())
        {
            cerr << "Ошибка: отсутствует обязательный параметр " << key << "\n";
            return false;
        }
    }
    const auto& testMode = params.at("--test-mode");
    if (testMode != "real" && testMode != "test")
    {
        cerr << "Ошибка: недопустимое значение --test-mode. Допустимые значения: real, test\n";
        return false;
    }
    const auto& version = params.at("--version");
    if (version.empty())
    {
        cerr << "Ошибка: версия пакета не может быть пустой\n";
        return false;
    }
    const auto& package = params.at("--package");
    if (package.empty())
    {
        cerr << "Ошибка: имя пакета не может быть пустым\n";
        return false;
    }
    const auto& repo = params.at("--repo");
    if (repo.empty())
    {
        cerr << "Ошибка: URL репозитория не может быть пустым\n";
        return false;
    }
    return true;
}
int main(int argc, char* argv[])
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if (argc != 11)
    {
        cerr << "Ошибка: неверное количество аргументов.\n";
        cerr << "Использование: " << argv[0] << " --package <имя пакета> --repo <URL или путь> --test-mode <real|test> --version <версия> --filter <подстрока>\n";
        cerr << "Пример: " << argv[0] << " --package my-package --repo http://repo.com --test-mode real --version 1.0.0 --filter test\n";
        return 1;
    }
    auto params = parseArguments(argc, argv);
    if (!validateParameters(params))
    {
        return 1;
    }
    printParameters(params);
    return 0;
}