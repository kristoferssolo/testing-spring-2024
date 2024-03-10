struct Muitnieks {
    uint employeeAvailable ID 4b
    uint timeToServe 4b
}

struct Citizen {
    uint timeArrived; 4b
    uint timeFinish; 4b
}



size for Employee: 
Worker count: 99
Citizen count: 4'000'000

99 * 8b + 4'000'000 * 8b = 792b + 32'000'000b = 
= 


How to determine the amount of time which can lie about
the queue?

Maximum time of serving is 100'000

Lets say we start serving someone at x:
How can we be sure that no one would be faster?

It must be 100001 lower than current time,
so if the time will be less by this time there will and 
it will we in priority
