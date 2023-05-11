#include "Job.h"
//A constructor that takes a priority and a description as arguments. 
Job::Job(Priority priority, const std::string& description) : priority(priority), description(description) {}

bool Job::operator<(const Job& other) const {
    return priority < other.priority;
}

bool Job::operator>(const Job& other) const {
    return priority > other.priority;
}
