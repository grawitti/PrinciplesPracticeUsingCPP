#include <random>
#include <functional>
#include <algorithm>

using namespace std;

// return vector<int> of random int numbers
vector<int> random_int_vec(int min, int max, int size)
{
    random_device rnd_dev;	// генератор истинно случайных чисел (СЧ)
    mt19937 m_gen(rnd_dev());	// генератор СЧ mersenne twister. Оператор() поризводит недетерминированные СЧ
    uniform_int_distribution<int> dist(min,max);	// распределение - указание диапазона целых чисел
    auto gen = bind(dist, m_gen);	// Создает объект являющийся связкой генератора и распределения
    vector<int> vec(size);
    generate(begin(vec), end(vec), gen);	// Заполняет вектор СЧ
    return vec;
}

// return ramdom int number
int random_int(int min, int max)
{
    random_device rnd_dev;	// генератор истинно случайных чисел (СЧ)
    mt19937 m_gen(rnd_dev());	// генератор СЧ mersenne twister. Оператор() поризводит недетерминированные СЧ
    uniform_int_distribution<int> dist(min,max);	// распределение - указание диапазона целых чисел
    return dist(m_gen);
}