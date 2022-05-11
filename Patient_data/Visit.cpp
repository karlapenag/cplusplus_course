//
// Created by Karla Angélica Peña Guerra on 5/8/22.
//
#include "Visit.h"

Visit::Visit(int fileNumber, int visitID, string date, string docsFirst, string docsLast) {
    this->file_number = fileNumber;
    this->visit_id_number = visitID;
    this->date = date;
    this->docs_first = docsFirst;
    this->docs_last = docsLast;

}

Visit::~Visit()= default;

std::ostream& operator<<(std::ostream& os, Visit visit)
{
    os << visit.getVisitIdNumber() << " ";
    os << visit.getDate() << " ";
    os << visit.getDocsFirst() << " ";
    os << visit.getDocsLast();

    return os;
}

int Visit::getVisitIdNumber() const {
    return visit_id_number;
}

const string &Visit::getDate() const {
    return date;
}

const string &Visit::getDocsFirst() const {
    return docs_first;
}

const string &Visit::getDocsLast() const {
    return docs_last;
}
