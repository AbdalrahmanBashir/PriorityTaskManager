#include <string>

enum class Priority {
    LOWEST = 1,
    LOW,
    MEDIUM,
    HIGH,
    HIGHEST
};

enum class Choice {
    ADD_JOB,
    REMOVE_JOB,
    UPDATE_JOB_PRIORITY,
    PRINT_JOBS,
    EXIT
};


class Job {
public:
    Priority priority;
    std::string description;

    Job(Priority priority, const std::string& description);

    bool operator<(const Job& other) const;
    bool operator>(const Job& other) const;
};

