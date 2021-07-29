#include "book.h"

bool operator==(book a, book b)
{
    if (a.author == b.author)return true;
    return false;
}

bool operator!=(book a, book b)
{
    if (a.author != b.author)return true;
    return false;
}

bool operator<=(book a, book b)
{
    if (a.author < b.author)return true;
    if (a.author > b.author)return false;
    else
    {
        if (a.name < b.name)return true;
        if (a.name > b.name)return false;
        else
        {
            if (a.code < b.code)return true;
            if (a.code > b.code)return false;
        }
    }
    return true;
}

bool operator>=(book a, book b)
{
    if (a.author > b.author)return true;
    if (a.author < b.author)return false;
    else
    {
        if (a.name > b.name)return true;
        if (a.name < b.name)return false;
        else
        {
            if (a.code > b.code)return true;
            if (a.code < b.code)return false;
        }
    }
    return true;
}

bool operator<(book a, book b)
{
    if (a.author < b.author)return true;
    if (a.author > b.author)return false;
    else
    {
        if (a.name < b.name)return true;
        if (a.name > b.name)return false;
        else
        {
            if (a.code < b.code)return true;
            if (a.code > b.code)return false;
        }
    }
    return false;
}

bool operator>(book a, book b)
{
    if (a.author > b.author)return true;
    if (a.author < b.author)return false;
    else
    {
        if (a.name > b.name)return true;
        if (a.name < b.name)return false;
        else
        {
            if (a.code > b.code)return true;
            if (a.code < b.code)return false;
        }
    }
    return false;
}

istream& operator >> (istream& in, book& a)
{
    in >> a.code >> a.author >> a.name;
    return in;
}

ostream& operator<<(ostream& ot, book& a)
{
    ot << a.code << " " << a.author << " " << a.name << endl;
    return ot;
}
