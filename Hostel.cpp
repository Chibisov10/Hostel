// Hostel.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <sys/types.h>
#include <filesystem>
#include <iterator>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;
  //  using std::filesystem;
class HotelRoom //Создаем класс НОМЕР
{
private:
    //int NumberRoom; //Порядковый номер
   // int RoomCapacity; //Вместимость номера
   // string RoomClass; //Класс номера
    //int CheckRoomBusy; // Занятость номера
   // int Price; // Цена номера
public:
    int NumberRoom;
    int RoomCapacity;
    string RoomClass;
    int CheckRoomBusy;
    int Price;
    //int RoomCapacity;
    int N, C, P, Check;
    string RClass;  
    HotelRoom()
    {
        NumberRoom = 0;
        RoomCapacity = 0;
        RoomClass = "";
        CheckRoomBusy = -1;
        Price = 0;
    }
    //~HotelRoom() {}
    HotelRoom(int NNumberRoom, int RRoomCapacity, string RRoomClass, int CCheckRoomBusy, int PPrice) 
    {
        NumberRoom = NNumberRoom;
        RoomCapacity = RRoomCapacity;
        RoomClass = RRoomClass;
        CheckRoomBusy = CCheckRoomBusy;
        Price = PPrice;
    }

    void SetRoom() // Функция заполнения номера
    {
        cout << "Enter a number of room : ";
        cin >> NumberRoom;
        cout << "Enter a capacity : ";
        cin >> RoomCapacity;
        cout << "Enter a class of room : ";
        cin >> RoomClass;
        cout << "Enter a employment of room : ";
        cin >> CheckRoomBusy;
        cout << "Enter a price of room : ";
        cin >> Price;
    }
    void GetRoom() // Функция вывода номера
    {
        cout << NumberRoom << " " << RoomCapacity << " " << RoomClass << " " << CheckRoomBusy << " " << Price << endl;
    }
    void GetNumberRoom() // Функция получения порядкового номера комнаты
    {
        //cout << NumberRoom << endl;
        N = NumberRoom;
    }
    void GetRoomCapacity()
    {
        C = RoomCapacity;
    }
    void ChangeRoomCapacity()
    {
        int n;
        cout << "Введите новое значение вместимости : ";
        cin >> n;
        cout << endl;
        RoomCapacity = n;
    }
    void GetRoomClass()
    {
        RClass = RoomClass;
    }
    void GetStatusRoom() //функция получения статуса номера
    {
        Check = CheckRoomBusy;
    }
    void GetPrice() // Функция получения цены номера
    {
        P = Price;
    }
};
class Guest
{
private:
    int ID;
public:
    string SurnameGuest;
    string NameGuest;
    Guest()
    {
        SurnameGuest = "";
        NameGuest = "";
    }
    Guest(string Surname, string Name)
    {
        SurnameGuest = Surname;
        NameGuest = Name;
    }
    void SetGuest()
    {
        cout << "Введите Фамилию Гостя : ";
        cin >> SurnameGuest;
        cout << "Введите ";
    }
};
void PrintChoise()
{
    cout << "Выберете действие, которое хотите совершить : " << endl;
    cout << "1. Добавить информацию о новом номере в гостинице" << endl;
    cout << "2. Изменить информацию о номере гостиницы" << endl;
    cout << "3. Удалить номер из номерного фонда гостиницы" << endl;
    cout << "4. Вывести все свободные номера" << endl;
    cout << "5. Вывести все номера в гостинице" << endl;
    cout << "6. Вывести текст из файлов на экран" << endl;
    cout << "7. Проверить информацию о госте" << endl;
    cout << "8. Заполнить информацию о новом госте и предложить номер" << endl;
    cout << "9. Закончить сессию" << endl;
}

ostream& operator<< (ostream& os, HotelRoom& room)
{
    os << room.NumberRoom << room.RoomCapacity << room.RoomClass << room.CheckRoomBusy << room.Price;
    return os;
}

istream& operator>> (istream& is, HotelRoom& room)
{
    is >> room.NumberRoom >> room.RoomCapacity >> room.RoomClass >> room.CheckRoomBusy >> room.Price;
    return is;
}

struct path_leaf_string
{
    string operator()(const filesystem::directory_entry & entry) const
    {
        return entry.path().filename().string();
    }
};
void read_directory(const string& name, vector<string>& v)
{
    std::filesystem::path p(name);
    std::filesystem::directory_iterator start(p);
    std::filesystem::directory_iterator end;
    std::transform(start, end, std::back_inserter(v), path_leaf_string());
}
void AllRRooms()
{
    ofstream fout;
    ifstream fin;
    string NoNo = "C:\\Users\\new_c_000\\source\\repos\\Hostel\\Hostel\\Rooms";
    string AllRooms = "Room-all.txt";
    string qqq;
    //HotelRoom RRRoom;
    vector<string> stringvec;
    read_directory(NoNo, stringvec);
    for (vector<string>::const_iterator i = stringvec.begin(); i != stringvec.end(); ++i)
    {
        //cout << *i << endl;
        fout.open(AllRooms, fstream::in | fstream::out | fstream::app);
        qqq = *i;
        qqq.erase(0, 5);
        qqq.erase(qqq.length() - 4, 4);
        fout.write((char*)&qqq, sizeof(qqq));
        cout << qqq << " ";
        fout.close();
    }
}
void NewRoom()
{
    HotelRoom RRRoom2, RRoom2;
    stringstream ss;
    string path = "Rooms/Room-", last = ".txt", numberR = "", name, AllRooms = "Room-all.txt";
    ofstream fout;
    ifstream fin;
    char ch;
    cout << "Все зарегистрированные ранее номера" << endl;
    fin.open(AllRooms, fstream::in);
    AllRRooms();
    cout << endl;
    RRRoom2.SetRoom();
    RRRoom2.GetRoom();
    RRRoom2.GetNumberRoom();
    ss << RRRoom2.N;
    numberR = ss.str();
    ss.str("");
    name = path + numberR + last;
    fout.open(name);
    fout.write((char*)&RRRoom2, sizeof(HotelRoom));
    fin.open(name);
    fin.read((char*)&RRoom2, sizeof(HotelRoom));
    RRoom2.GetRoom();
    cout <<"Номер успешно создан!"<<endl;
    cout << "YES" << endl;
    fin.close();
    fout.close();
}
void DeleteRoom()
{
    string path = "Rooms/Room-", last = ".txt";
    stringstream ss;
    int num;
    cout << "В вашем номерном фонде есть следующие номера : " << endl;
    AllRRooms();
    cout << "Какой номер вы хотите удалить?" << endl;
    cout << "Ввелите номер : ";
    cin >> num;
    ss << num;
    path = path + ss.str() + last;
    cout << path << endl;
    if (remove(path.c_str()) != 0)
       cout << "Такого номера не было";
    else cout << "Номер успешно удален из гостиничного фонда!";
    cout << endl;
}
void ChangeRoom()
{
    HotelRoom RRoom, RRoom2;
    ofstream fout;
    ifstream fin;
    string path = "Rooms/Room-", last = ".txt";
    stringstream ss;
    int num;
    cout << "В вашем номерном фонде есть следующие номера : " << endl;
    AllRRooms();
    cout << endl;
    cout << "Введите порядковый номер комнаты, которую вы хотите изменить" << endl;
    cin >> num;
    ss << num;
    path = path + ss.str() + last;
    /*fin.open(path, fstream::in | fstream::out | fstream::app);
    fin >> RRoom;
    fin.close();*/
    fin.open(path);
    fin.read((char*)&RRoom, sizeof(HotelRoom));
    RRoom.GetRoom();
    RRoom.ChangeRoomCapacity();
    cout << endl;
    //RRoom.GetRoom();
    fout.open(path);
    fout.write((char*)&RRoom, sizeof(HotelRoom));
    RRoom.GetRoom();
    fin.close();
    fout.close();
}
void FreeRooms()
{
    //ofstream fout;
    ifstream fin;
    HotelRoom RRRoom, RRoom;
    //istringstream iss;
    string NoNo = "C:\\Users\\new_c_000\\source\\repos\\Hostel\\Hostel\\Rooms";
    string path = "Rooms/Room-", last = ".txt", name;
    string AllRooms = "Room-all.txt";
    string qqq, q="";
    int num;
    vector<string> stringvec;
    read_directory(NoNo, stringvec);
    for (vector<string>::const_iterator i = stringvec.begin(); i != stringvec.end(); ++i)
    {
       // cout << *i << endl;
       // fout.open(AllRooms, fstream::in | fstream::out | fstream::app);
        qqq = *i;
        qqq.erase(0, 5);
        qqq.erase(qqq.length() - 4, 4);
        stringstream iss(qqq, istringstream::in);
        iss >> num;
        name = path + qqq + last;
        //HotelRoom RRRoom, RRoom;
       //fout.close();
       // fout.open(name, fstream::in | fstream::out | fstream::app);
        //fout << RRRoom;
        //cout << RRRoom << endl;
        fin.open(name);
        fin.read((char*)&RRoom, sizeof(HotelRoom));
       // RRoom.GetRoom();
        //RRRoom.GetStatusRoom();
        if (RRoom.CheckRoomBusy == 0)
        {
            cout << RRoom.NumberRoom << " ";
        }
       // cout << q << endl;
        //fin.close();
      // cout << num << endl;
       num = 0;
      // cout << num << endl;
        //RRoom.~HotelRoom();
        //RRoom.GetRoom();
       qqq = "";
       //cout << "YES" << endl;
       fin.close();
    }
    cout << endl;
    //fin.close();
}

int main()

{
    setlocale(LC_ALL, "ru");
    int n = 0, i = 0, t = 0, z;
    int q = 1;
    int a = 0;
    double x;
    // stringstream ss;
     //string path = "Rooms/Room-", last = ".txt", numberR = "", name, AllRooms="Rooms/Room-all.txt";
    string NameUser;
    //string NoNo = "C:\\Users\\new_c_000\\source\\repos\\Hostel\\Hostel\\Rooms";
     ofstream fout;
     ifstream fin;
    HotelRoom First[60];
    HotelRoom RRoom3;
    vector<string> stringvec;
    // AllRRooms();
    cout << "Введите ваше имя : ";
    cin >> NameUser;
    cout << "Здравствуйте, " << NameUser << "!" << endl;
    while (t != 7) 
    {
    PrintChoise();
    cin >> t;
    switch (t)
    {
    case 1:
        cout << "Вы ввели 1" << endl;
        NewRoom();
        cout << "Хорошо!" << endl;
        break;
    case 2:
        cout << "Вы ввели 2" << endl;
        ChangeRoom();
        break;
    case 3:
        cout << "Вы ввели 3" << endl;
        DeleteRoom();
        break;
    case 4:
        cout << "Вы ввели 4" << endl;
        FreeRooms();
        break;
    case 5:
        cout << "Вы ввели 5" << endl;
        AllRRooms();
        cout << endl;
        break;
    case 6:
        cout << "Вы ввели 6" << endl;
        fin.open("Rooms/Room-106.txt");
        fin.read((char*)&RRoom3, sizeof(HotelRoom));
        fin.close();
        RRoom3.GetRoom();
        fin.open("Rooms/Room-102.txt");
        fin.read((char*)&RRoom3, sizeof(HotelRoom));
        fin.close();
        RRoom3.GetRoom();
        fin.open("Rooms/Room-103.txt");
        fin.read((char*)&RRoom3, sizeof(HotelRoom));
        fin.close();
        RRoom3.GetRoom();
        fin.open("Rooms/Room-104.txt");
        fin.read((char*)&RRoom3, sizeof(HotelRoom));
        fin.close(); 
        RRoom3.GetRoom();
        fin.open("Rooms/Room-105.txt");
        fin.read((char*)&RRoom3, sizeof(HotelRoom));
        fin.close();
        RRoom3.GetRoom();
        fin.open("Rooms/Room-106.txt");
        fin.read((char*)&RRoom3, sizeof(HotelRoom));
        fin.close();
        RRoom3.GetRoom();
        break;
    case 7:
        cout << "Вы ввели 7" << endl;
        cout << "Спасибо за вашу работу!" << endl;
        t = 7;
        break;

    default:
        cout << "Введено неправильно значение" << endl;
        break;
    }
}
     //Заводим информацию о комнатах
     /*while (q != 0)
     {
         First[n].SetRoom();
         ss << n + 1;
         numberR = ss.str();
         ss.str("");
         name = path + numberR + last;
         fout.open(name);
         fout.write((char*)&First[n], sizeof(HotelRoom));
         fout.close();

         fout.open(AllRooms, fstream::in| fstream::out| fstream::app);
         First[n].GetNumberRoom();
         fout<<First[n].N<<" ";
         fout.close();
         cout << endl;
         cout << "Is that all the rooms in the hostel ? (Yes - 0, No - 1)" << endl;
         cin >> q;
         n += 1;
     }*/

     /* cout << "All available rooms : " << endl; //Выводим все свободные номера
      ss.str("");
      for (i = 0; i < n; i++)
      {
          ss << i+1 ;
          numberR = ss.str();
          ss.str("");
          name = path + numberR + last;
          //cout << name << endl;
          fin.open(name);
          fin.read((char*)&RRoom, sizeof(HotelRoom));
         // cout << "YES" << endl;
          RRoom.GetStatusRoom();
          if (RRoom.Check == 0)
          {
             RRoom.GetNumberRoom();
          }
          fin.close();
      }*/

    cout << "All";

    cout << endl;
    return 0;
}


