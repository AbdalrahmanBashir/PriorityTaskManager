#include "PriorityQueue.h"
#include <stdexcept>
#include <iostream>
#include<string>
#include <fstream>

void PriorityQueue::add_job(const Job& job) {
    queue.push(job); // Adds a new job to the priority queue.
}

bool PriorityQueue::remove_job() {
    if (queue.empty()) {
        return false; // Returns false if the queue is empty and no jobs can be removed.
    }

    queue.pop(); // Removes the highest priority job from the queue.
    return true; // Returns true to indicate that a job was successfully removed.
}

Job PriorityQueue::get_highest_priority_job() const {
    if (queue.empty()) {
        // Throws an exception if the queue is empty
        throw std::logic_error("Priority queue is empty");
    }

    return queue.top(); // Returns the highest priority job in the queue
}

bool PriorityQueue::is_empty() const {
    return queue.empty(); // Returns true if the queue is empty, false otherwise
}

size_t PriorityQueue::get_num_jobs() const {
    return queue.size(); // Returns the number of jobs currently in the queue
}

void PriorityQueue::write_jobs(const std::string& filename)
{
    std::ofstream file(filename); // Opens a new file for writing
    if (!file.is_open()) {
        // Outputs an error message if the file could not be opened
        std::cerr << "Error: could not open file " << filename << std::endl; 
        return; 
    }
    std::vector<Job> jobs;
    while (!queue.empty()) {
        jobs.push_back(queue.top()); // Stores the highest priority job in a vector
        queue.pop(); // Removes the job from the queue
    }
    std::reverse(jobs.begin(), jobs.end()); // Reverses the vector to output jobs in order of decreasing priority

    for (const auto& job : jobs) {
        file << static_cast<int>(job.priority) << " " << job.description << std::endl; // Writes the job's priority and description to the file
        queue.push(job); // Adds the job back to the queue
    }
}

void PriorityQueue::read_jobs(const std::string& filename)
{

    std::ifstream file(filename); // Opens an existing file for reading
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl; // Outputs an error message if the file could not be opened
        return; // Exits the function if the file could not be opened
    }
    while (!file.eof()) { // Loops until the end of the file is reached
        std::vector<Job> jobs;
        Priority priority;
        std::string description;
        int priority_int;
        file >> priority_int; // Reads the priority value from the file
        if (priority_int < 1 || priority_int > 5) {
            std::cerr << "Error: invalid priority value " << priority_int << std::endl; // Outputs an error message if the priority value is invalid
            continue; // Skips to the next line in the file if the priority value is invalid
        }
        priority = static_cast<Priority>(priority_int); // Converts the priority value to an enum value
        std::getline(file >> std::ws, description); // Reads the job description from the file
        if (!description.empty()) {
            add_job(Job(priority, description)); // Adds the job to the priority queue

            }
        }
}

