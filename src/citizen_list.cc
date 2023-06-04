#include <citizen/citizen.h>
#include <stdexcept>
using namespace citizen;
using namespace std;

int CitizenList::size() const {
    return _data.size(); 
}
CitizenList::CitizenList(const CitizenList& other)
{
    _data.reserve(other.size());
    for (const auto& ptr : other._data)
    {
        _data.push_back(ptr->clone());
    }
}
CitizenPtr CitizenList::operator[](const int index) const {
    if (index < 0) {
        throw out_of_range("[CitizenList::operator[]] Index is out of range.");
    }
    return _data[index];
}
CitizenList& CitizenList::operator=(const CitizenList& rhs) {
    CitizenList copy(rhs);
    copy.swap(*this);
    return *this;
}
void CitizenList::swap(CitizenList& other) {
    std::swap(this->_data, other._data);
}
void CitizenList::add(CitizenPtr f) {
    _data.push_back(f);
}
void CitizenList::insert(CitizenPtr people, int index)
{
    if (index < 0)
    {
        throw out_of_range("[CitizenList::operator[]] Index is out of range.");
    }
    auto iter = _data.cbegin();
    _data.emplace(iter + index, people);
}
void CitizenList::remove(int index)
{
    if (index < 0)
    {
        throw out_of_range("[CitizenList::operator[]] Index is out of range.");
    }
    auto iter = _data.cbegin();
    _data.erase(iter + index);
}
int citizen::search_max_payment(const CitizenList& _Citizen)
{
    int max_index = -1;
    double max_payment = 0;

    auto n = _Citizen.size();

    for (int i = 0; i < n; i++)
    {
        auto value = _Citizen[i]->payment();
        if (value > max_payment || max_index == -1)
        {
            max_index = i;
            max_payment = value;
        }
    }
    return max_index;
}