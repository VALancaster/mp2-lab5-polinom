#ifndef TSINGLYLIST_H
#define TSINGLYLIST_H

#include <vector>

using namespace std;

template<typename T>
class TSinglyList {
private:
	struct TNode
	{
		T value; // значение 
		TNode* pNext; // указатель на следующее звено
	};
	TNode* pFirst; // указатель на первое звено
	size_t sz; // размер списка
public:
	TSinglyList(); // конструктор по умолчанию
	TSinglyList(const vector<T>& v); // конструктор преобразования типа (из вектора)
	TSinglyList(const TSinglyList& list); // конструктор копирования
	
	TSinglyList& operator=(const TSinglyList& list);

	~TSinglyList(); // деструктор

    void swap(TSinglyList& l, TSinglyList& r) noexcept;
	size_t size() const noexcept;
	bool IsEmpty() const noexcept;
	T& Front() noexcept;
	void PushFront(const T& val);
	void PopFront() noexcept;
	TNode* ToPos(size_t pos);
    TNode* const ToPos(size_t pos) const;
	T& operator[](size_t pos);
	const T& operator[](size_t pos) const;
	void PushAfter(size_t pos, const T& val);
	void EraseAfter(size_t pos);
    void Clear();
};

// Реализации методов

template<typename T>
TSinglyList<T>::TSinglyList() : pFirst(nullptr), sz(0) {}

template<typename T>
TSinglyList<T>::TSinglyList(const vector<T>& v) : pFirst(nullptr), sz(0)
{
    for (size_t i = v.size(); i > 0; i--)
        PushFront(v[i - 1]);
}

template<typename T>
TSinglyList<T>::TSinglyList(const TSinglyList& list) : pFirst(nullptr), sz(list.sz)
{
    if (list.pFirst == nullptr)
        return;
    typename TSinglyList<T>::TNode* pNew = pFirst = new TNode{ *list.pFirst }; // звено для копирования первого элемента списка
    // { *list.pFirst} - инициализирует значение звена копией данных из первого звена списка list
    for (; pNew->pNext != nullptr; pNew = pNew->pNext)
        pNew->pNext = new TNode{ *pNew->pNext };
}

template<typename T>
TSinglyList<T>& TSinglyList<T>::operator=(const TSinglyList& list)
{
    if (this != &list)
    {
        TSinglyList tmp(list);
        swap(*this, tmp);
    }
    return *this;
}

template<typename T>
TSinglyList<T>::~TSinglyList()
{
    typename TSinglyList<T>::TNode* p;
    while (pFirst != nullptr)
    {
        p = pFirst;
        pFirst = pFirst->pNext;
        delete p;
    }
}

template<typename T>
void TSinglyList<T>::swap(TSinglyList& l, TSinglyList& r) noexcept
{
    using std::swap;
    swap(l.pFirst, r.pFirst);
    swap(l.sz, r.sz);
}

template<typename T>
size_t TSinglyList<T>::size() const noexcept
{
    return sz;
}

template<typename T>
bool TSinglyList<T>::IsEmpty() const noexcept
{
    return sz == 0;
}

template<typename T>
T& TSinglyList<T>::Front() noexcept
{
    return pFirst->value;
}

template<typename T>
void TSinglyList<T>::PushFront(const T& val)
{
    typename TSinglyList<T>::TNode* node = new TNode{ val, pFirst };
    pFirst = node;
    sz++;
}

template<typename T>
void TSinglyList<T>::PopFront() noexcept
{
    typename TSinglyList<T>::TNode* p = pFirst;
    pFirst = pFirst->pNext;
    delete p;
    sz--;
}

template<typename T>
typename TSinglyList<T>::TNode* TSinglyList<T>::ToPos(size_t pos)
{
    typename TSinglyList<T>::TNode* p = pFirst;
    for (size_t i = 0; i < pos; i++)
    {
        if (p == nullptr)
            throw std::out_of_range("Invalid position");
        p = p->pNext;
    }
    return p;
}

template<typename T>
typename TSinglyList<T>::TNode* const TSinglyList<T>::ToPos(size_t pos) const
{
    typename TSinglyList<T>::TNode* p = pFirst;
    for (size_t i = 0; i < pos; i++)
    {
        if (p == nullptr)
            throw std::out_of_range("Invalid position");
        p = p->pNext;
    }
    return p;
}

template<typename T>
T& TSinglyList<T>::operator[](size_t pos)
{
    typename TSinglyList<T>::TNode* p = ToPos(pos);
    return p->value;
}

template<typename T>
const T& TSinglyList<T>::operator[](size_t pos) const
{
    return ToPos(pos)->value;
}

template<typename T>
void TSinglyList<T>::PushAfter(size_t pos, const T& val)
{
    typename TSinglyList<T>::TNode* p = ToPos(pos);
    typename TSinglyList<T>::TNode* pNew = new TNode{ val, p->pNext };
    p->pNext = pNew;
    sz++;
}

template<typename T>
void TSinglyList<T>::EraseAfter(size_t pos)
{
    typename TSinglyList<T>::TNode* p = ToPos(pos);
    typename TSinglyList<T>::TNode* pDel = p->pNext;
    p->pNext = pDel->pNext;
    delete pDel;
    sz--;
}

template <typename T>
void TSinglyList<T>::Clear()
{
    while (!IsEmpty())
    {
        PopFront();
    }
}

#endif