#include "pch.h"
#include <iostream>
// Простейшая система аутентификации — 
// посимвольное сравнение пароля 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "windows.h" //библиотека audiere её требует
#include "audiere.h" //сама библиотека

#define PASSWORD_SIZE 100
#define PASSWORD "home\n"
// Этот перенос нужен затем, чтобы 
// не выкусывать перенос из строки,
// введенной пользователем

using namespace std;
using namespace audiere;

int main()
{
	setlocale(LC_ALL,"Russian");
	
	// Буфер для пароля, введенного пользователем 
	char buff[PASSWORD_SIZE];
	// Главный цикл аутентификации 
	// Счетчик неудачных попыток аутентификации 
	for (int count = 0;count < 20; count++)
	{
		// Запрашиваем и считываем пользовательский 
		// пароль
		printf("Введите пароль:");
		fgets(&buff[0], PASSWORD_SIZE, stdin);
		// Сравниваем оригинальный и введенный пароль 
		if (strcmp(&buff[0], PASSWORD)) {
			// Если пароли не совпадают — «ругаемся»
			cout << "Неверный пароль\n" << endl;
			Sleep(500);
			system("cls");
		}
		// Иначе (если пароли идентичны)
		// выходим из цикла аутентификации
		else break;
		// Увеличиваем счетчик неудачных попыток 
		// аутентификации и, если все попытки 
		// исчерпаны, завершаем программу 
	}
	// Раз мы здесь, то пользователь ввел правильный 
	// пароль 
	cout << "**Доступ разрешен**\n" << endl;
	AudioDevicePtr device = OpenDevice(); //Для начала нужно открыть AudioDevice 
	OutputStreamPtr sound = OpenSound(device, "tm1_objective_location1.wav", false); //создаем поток для нашего звука
	sound->setRepeat(false);
	sound->setVolume(1.0f);
	sound->play();
	
	system("pause");

}