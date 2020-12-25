#pragma once
class Lider;
class Trailer;


class TopSort
{
private:
	Lider* head_, * tail_; // фиктивные
	friend class Lider;
	friend class Trailer;
public:
	TopSort();
	~TopSort();
	void add(Lider*, Lider*);
	Lider* addToHead(int);
	void addToTail(Lider*);
	void remove(Lider*);
	void print();
	bool empty();
	Lider* findKey(int);
	Lider* findCount(int);
	void addEdge(int, int);
	void deleteFromHead();
};


class Lider
{
	int key_, count_;
	Lider* next_, * prev_;
	Trailer* headtr_;
	friend class TopSort;
	friend class Trailer;
public:
	Lider();
	Lider(int);
	Lider(Lider*, Lider*);
	~Lider();  // удалить список трейлеров
	void addTrailer(Lider*);
	void decTrValues();
	void clear();
	void deleteFromHead();
};


class Trailer
{
private:
	Lider* node_;
	Trailer* next_;
	friend class TopSort;
	friend class Lider;
public:
	Trailer();
	Trailer(Lider*, Trailer*);
};