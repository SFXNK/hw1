#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){
  if(size_==0 || tail_->last==ARRSIZE-2){
    Item* tmp=new Item();
    tmp->val[0]=val;
    tmp->last=1;
    if(size_==0){
      tail_=tmp;
      head_=tmp;
    }
    else{
      tail_->next=tmp;
      tmp->prev=tail_;
      tail_=tmp;
    }
    size_++;
  }
  else{
    tail_->val[tail_->last++]=val;
    size_++;
  }
}

void ULListStr::push_front(const std::string& val){
  if(size_==0 || head_->first==0){
    Item* tmp=new Item();
    tmp->val[0]=val;
    tmp->last=1;
    if(size_==0){
      tail_=tmp;
      head_=tmp;
    }
    else{
      head_->prev=tmp;
      tmp->next=head_;
      head_=tmp;
    }
    size_++;
  }
  else{
    head_->val[--(tail_->first)]=val;
    size_++;
  }
  
}

void ULListStr::pop_back(){
  if(size_==0)
    return;
  if(size_==1){
    delete tail_;
    head_=NULL;
    tail_=NULL;
    size_=0;
    return;
  }
  tail_->val[--(tail_->last)]='\0';
  size_--;
  if(tail_->first==tail_->last){
    Item* tmp=tail_->prev;
    delete tail_;
    tail_=tmp;
  }
  
}

void ULListStr::pop_front(){
  if(size_==0)
    return;
  if(size_==1){
    delete head_;
    head_=NULL;
    tail_=NULL;
    size_=0;
    return;
  }
  head_->val[head_->first++]='\0';
  size_--;
  if(head_->first==head_->last){
    Item* tmp=head_->next;
    delete head_;
    head_=tmp;
  }

}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const{
  return head_->val[tail_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* p=head_;
  int cnt=0;
  while(p!=NULL){
    if(cnt+p->last-p->first>loc){
      return &p->val[loc-cnt+p->first];
    }
    else{
      cnt+=p->last-p->first;
      p=p->next;
    }
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
