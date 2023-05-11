#include <queue>
#include <string>
#include "Job.h"

class PriorityQueue {
public:
    void add_job(const Job& job);
    bool remove_job();
    Job get_highest_priority_job() const;
    bool is_empty() const;
    size_t get_num_jobs() const;
    void write_jobs(const std::string& filename);
    void read_jobs(const std::string& filename);


private:
    std::priority_queue<Job, std::vector<Job>, std::greater<>> queue;
};

