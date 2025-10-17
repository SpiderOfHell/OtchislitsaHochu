"# OtchislitsaHochu" 
<!DOCTYPE html>
<html>
<head>
    <title>Инструмент визуализации графа зависимостей</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 40px; line-height: 1.6; }
        h1, h2 { color: #2c3e50; }
        code { background: #f4f4f4; padding: 2px 6px; border-radius: 3px; }
        pre { background: #f8f8f8; padding: 15px; border-left: 4px solid #3498db; overflow-x: auto; }
        .section { margin-bottom: 30px; }
    </style>
</head>
<body>
    <h1>Инструмент визуализации графа зависимостей</h1>
    
    <div class="section">
        <h2>Общее описание</h2>
        <p>CLI-приложение для анализа и визуализации графа зависимостей пакетов Java (Maven). Приложение разработано в рамках практической работы по дисциплине "Конфигурационное управление".</p>
    </div>

    <div class="section">
        <h2>Функции и настройки</h2>
        <h3>Поддерживаемые параметры:</h3>
        <ul>
            <li><code>--package</code> - имя анализируемого пакета (обязательный)</li>
            <li><code>--repo</code> - URL репозитория или путь к файлу тестового репозитория (обязательный)</li>
            <li><code>--test-mode</code> - режим работы (real/test) (обязательный)</li>
            <li><code>--version</code> - версия пакета (обязательный)</li>
            <li><code>--filter</code> - подстрока для фильтрации пакетов (обязательный)</li>
        </ul>
        
        <h3>Функциональность:</h3>
        <ul>
            <li>Парсинг аргументов командной строки</li>
            <li>Валидация входных параметров</li>
            <li>Обработка ошибок ввода</li>
            <li>Вывод параметров конфигурации</li>
        </ul>
    </div>

    <div class="section">
        <h2>Сборка и запуск</h2>
        
        <h3>Компиляция:</h3>
        <pre>g++ -o dependency_analyzer main.cpp</pre>
        
        <h3>Запуск:</h3>
        <pre>./dependency_analyzer --package &lt;имя пакета&gt; --repo &lt;URL или путь&gt; --test-mode &lt;real|test&gt; --version &lt;версия&gt; --filter &lt;подстрока&gt;</pre>
        
        <h3>Пример использования:</h3>
        <pre>./dependency_analyzer --package my-package --repo http://repo.com --test-mode real --version 1.0.0 --filter test</pre>
    </div>

    <div class="section">
        <h2>Примеры вывода</h2>
        
        <h3>Успешный запуск:</h3>
        <pre>
=== Параметры конфигурации ===
--package: my-package
--repo: http://repo.com
--test-mode: real
--version: 1.0.0
--filter: test
==============================

=== Демонстрация обработки ошибок ===
Тест 1: Не все обязательные параметры - ДОЛЖНА БЫТЬ ОШИБКА
Тест 2: Некорректный test-mode - ДОЛЖНА БЫТЬ ОШИБКА
Тест 3: Пустые значения параметров - ДОЛЖНА БЫТЬ ОШИБКА
=====================================
Все параметры корректны. Приложение готово к работе.
        </pre>
        
        <h3>Ошибка валидации:</h3>
        <pre>
Ошибка: недопустимое значение --test-mode. Допустимые значения: real, test
        </pre>
    </div>

    <div class="section">
        <h2>Требования</h2>
        <ul>
            <li>Компилятор C++ с поддержкой C++11</li>
            <li>ОС Windows (из-за использования windows.h для кодировки)</li>
            <li>Библиотеки: iostream, string, vector, map, algorithm</li>
        </ul>
    </div>

    <div class="section">
        <h2>Структура проекта</h2>
        <pre>
project/
├── main.cpp          # Основной исходный файл
├── dependency_analyzer # Исполняемый файл (после компиляции)
└── README.html       # Документация
        </pre>
    </div>
</body>
</html>