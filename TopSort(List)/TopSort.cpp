#include<iostream>
#include "TopSort.h"


TopSort::TopSort()
{
	head_ = new Lider();
	tail_ = new Lider(head_, 0);
	head_->next_ = tail_;
}


TopSort::~TopSort()
{
	for (; !empty();)
		deleteFromHead();
}


void TopSort::print()
{
	for (Lider* i = head_->next_; i != tail_; i = i->next_)
		std::cout << i->key_ << " ";
}


bool TopSort::empty()
{
	if (head_->next_ == tail_)
		return true;
	return false;
}


Lider* TopSort::findKey(int key)
{
	for (Lider* node = head_->next_; node != tail_; node = node->next_)
		if (node->key_ == key)
			return node;
	return nullptr;
}


Lider* TopSort::findCount(int count)
{
	for (Lider* node = head_->next_; node != tail_; node = node->next_)
		if (node->count_ == count)
			return node;
	return nullptr;
}


void TopSort::add(Lider* prev, Lider* node)
{
	Lider* next = prev->next_;
	node->prev_ = prev;
	node->next_ = next;
	prev->next_ = node;
	next->prev_ = node;
}


Lider* TopSort::addToHead(int key)
{
	Lider* node = new Lider;
	node->key_ = key;
	add(head_, node);
	return node;
}


void TopSort::addToTail(Lider* node)
{
	add(tail_->prev_, node);
}


void TopSort::remove(Lider* node)
{
	Lider* prev = node->prev_;
	Lider* next = node->next_;
	prev->next_ = next;
	next->prev_ = prev;
}


void TopSort::deleteFromHead()
{
	if (!empty()) {
		Lider* node = head_->next_;
		remove(node);
		delete node;
	}
}


void TopSort::addEdge(int a, int b)
{
	Lider* pa, * pb;
	if (findKey(a))
		pa = findKey(a);
	else
		pa = addToHead(a);
	if (findKey(b))
		pb = findKey(b);
	else
		pb = addToHead(b);
	pb->count_++;
	pa->addTrailer(pb);
}


Lider::Lider()
{
	key_ = count_ = 0;
	next_ = prev_ = 0;
	headtr_ = 0;
}


Lider::Lider(int key)
{
	key_ = key;
	count_ = 0;
	next_ = prev_ = 0;
	headtr_ = 0;
}


Lider::Lider(Lider* prev, Lider* next)
{
	prev_ = prev;
	next_ = next;
	key_ = count_ = 0;
	headtr_ = nullptr;
}


Lider::~Lider()
{
	clear();
}


void Lider::addTrailer(Lider* node)
{
	Trailer* t = new Trailer(node, headtr_);
	headtr_ = t;
}


void Lider::decTrValues()
{
	for (Trailer* i = headtr_; i; i = i->next_)
		i->node_->count_--;
}


void Lider::clear()
{
	for (; headtr_;)
		deleteFromHead();
}


void Lider::deleteFromHead()
{
	Trailer* node = headtr_;
	headtr_ = headtr_->next_;
	delete node;
}


Trailer::Trailer()
{
	node_ = 0;
	next_ = 0;
}


Trailer::Trailer(Lider* node, Trailer* head)
{
	node_ = node;
	next_ = head;
}