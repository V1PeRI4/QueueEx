#include <iostream>
#include <cstring>

using namespace std;

struct Queue{
    int info;
    Queue* next;
} *beginQueue, * endQueue;


Queue* InStack(Queue* p, int in) {
    Queue* t = new Queue; 
    t->info = in; 
    t->next = p; 
    return t;
}


void viewStack(Queue* p) {
    Queue* t = p;
    while (t != NULL) {
        cout << " " << t->info << endl;
        t = t->next;
    }
}


void delStack(Queue** p) {
    while (*p != NULL) {
        endQueue = *p;
        *p = (*p)->next;
        delete endQueue;
    }
}


int findMaxEl(Queue* p) {
    int  result = 0;
    Queue* t = p;
    while (t != NULL) {
        if (result < t->info)
            result = t->info;

        t = t->next;
    }
    return result;
}


int findMinEl(Queue* p) {
    int  result = 99999;
    Queue* t = p;
    while (t != NULL) {
        if (result > t->info)
            result = t->info;

        t = t->next;
    }
    return result;
}


void delElBetweenMinAndMax(Queue* p) {
    int valueMaxEl = findMaxEl(beginQueue);
    int valueMinEl = findMinEl(beginQueue);

    cout << "Элементы между {" << valueMaxEl << "} и {" << valueMinEl << "} удалены..." << endl;
    
    Queue* t = p;
    while (t != NULL) {

        if (t->info == valueMinEl || t->info == valueMaxEl)
        {
            while (true)
            {
                t = t->next;

                if (t->info == valueMinEl || t->info == valueMaxEl)
                {
                    break;
                }
                t->info = NULL;
            }
        }
        t = t->next;
    }
}


int main() 
{
    setlocale(LC_ALL, "Russian");

    int i, in, n, command;

    while (true) {
        system("cls");
        
        cout << "\n1. Создать очередь."
            "\n2. Добавить элементы в очередь."
            "\n3. Посмотреть очередь."
            "\n4. Найти максимальный и минимальный элементы и удалить значения между ними."
            "\n5. Удалить очередь."
            "\n0. Выход.\n" << endl;
        cin >> command;
        switch (command) {
        default:
            cout << "Неизвестная команда" << endl;
            break;

        case 1: case 2:
            
            if (command == 1 && beginQueue != NULL) {
                cout << "Очистка памяти" << endl;

                system("pause");
                break;
            }
            cout << "Введите кол-во элементов: ";
            cin >> n;
            for (i = 1; i <= n; i++) {
                in = rand();
                beginQueue = InStack(beginQueue, in);
            }
            if (command == 1)
                cout << "Создано " << n << " эл." << endl;
            else cout << "Добавлено " << n << " эл." << endl;

            system("pause");
            break;

        case 3:
            if (!beginQueue) {
                cout << "Очередь пуста!" << endl;

                system("pause");
                break;
            }

            cout << "\n---Queue---" << endl;
            viewStack(beginQueue);

            system("pause");
            break;

        case 4:
            if (!beginQueue) {
                cout << " пуст!" << endl;

                system("pause");
                break;
            }
            
            delElBetweenMinAndMax(beginQueue);

            system("pause");
            break;

        case 5:
            delStack(&beginQueue);
            cout << "Память чиста!" << endl;

            system("pause");
            break;

        case 0:
            if (beginQueue != NULL)
                delStack(&beginQueue);

            system("pause");
            return 0;
        }
    }


}