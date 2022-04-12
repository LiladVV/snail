
#include "sales_data.h"

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;

/*
 * ���ⶨ���Ա����
 * ����������һ��
 * ��������(������������Ϊ��������������)
 * const����
 */
double SalesData::AvgPrice() const
{
    return units_sold_ ? revenue_ / units_sold_ : 0;
}

std::ostream& operator<<(std::ostream &os, const SalesData &item)
{
    os << item.Isdn() << " " << item.units_sold_ << " "
       << item.revenue_ << " " << item.AvgPrice();
    return os;
}

std::istream& operator>>(std::istream &in, SalesData &item)
{
    double price;
    in >> item.book_no_ >> item.units_sold_ >> price;

    if (in)
        item.revenue_ = item.units_sold_ * price;
    else
        item = SalesData();

    return in;
}


SalesData operator+(const SalesData &lhs, const SalesData &rhs)
{
    // SalesData ret(lhs);
    // ret += rhs;
    // return ret;

    SalesData ret = lhs;
    ret.units_sold_ += rhs.units_sold_;
    ret.revenue_ += rhs.revenue_;
    return ret;
}
///ִ�к�����֮ǰ,��ԱĬ�ϳ�ʼ��
SalesData::SalesData(istream &in)
{
    Read(in, *this);
    // in >> *this;
}

SalesData& SalesData::operator=(const SalesData &rhs)
{
    book_no_ = rhs.book_no_;
    units_sold_ = rhs.units_sold_;
    revenue_ = rhs.revenue_;
    return *this;
}

SalesData& SalesData::operator=(const string &isbn)
{
    book_no_ = isbn;
    return *this;
}

SalesData& SalesData::operator+=(const SalesData &rhs)
{
    // units_sold_ += rhs.units_sold_;
    // revenue_ += rhs.revenue_;
    // return *this;

    *this = (*this) + rhs;
    return *this;
}

//��ʼ���б����ڶ��崦
// SalesData::SalesData(std::istream &in) : SalesData()
//{
//    //std::cout << "func d" << std::endl;
//    Read(in, *this);
//}





istream &Read(istream &in, SalesData &item)
{
    double price = 0;
    in >> item.book_no_ >> item.units_sold_ >> price;
    item.revenue_ = item.units_sold_ * price;
    return in;
}

ostream &Print(ostream &out, const SalesData &item)
{
    out << item.book_no_ << " " << item.units_sold_ << " "
        << item.revenue_ << " " << item.AvgPrice();
    return out;
}

SalesData Add(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs;
    sum.Combine(rhs);
    return sum;
}
