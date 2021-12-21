#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm> // std::min_element, std::max_element
#include <numeric>   // std::reduce (C++17)

int main (int argc, char *argv[])
{
    // Print information about the minimum representable period.
    auto num = std::chrono::high_resolution_clock::period::num;
    auto den = std::chrono::high_resolution_clock::period::den;
    auto dur = (double) std::chrono::high_resolution_clock::period::num
             / std::chrono::high_resolution_clock::period::den;

    std::cout << "The period of the clock tick for std::chrono::high_resolution_clock in seconds is " << num << "/" << den << ". ";;

    std::cout << "This means the minimum representable duration is " << dur << " seconds, which is " << dur * 1e9 << " nanosecond(s)." << std::endl;

    // Run now() in a loop and report the observed deltas
    int n = 101;
    std::vector<std::chrono::time_point<std::chrono::high_resolution_clock>> times(n);
    for (auto i = begin(times); i != end(times); i++) {
        *i = std::chrono::high_resolution_clock::now();
    }

    std::vector<std::chrono::duration<double>> delta;
    for(auto i = 1; i < times.size(); i++) {
        delta.push_back(times[i] - times[i-1]);
    }

    auto min_delta = *std::min_element(begin(delta), end(delta));
    auto max_delta = *std::max_element(begin(delta), end(delta));

    auto const count = static_cast<double>(delta.size());
    auto avg_delta = std::reduce(delta.begin(), delta.end()) / count;

    auto min_ns = min_delta.count() * 1e9;
    auto max_ns = max_delta.count() * 1e9;
    auto avg_ns = avg_delta.count() * 1e9;

    std::cout << std::endl;
    std::cout << "Over " << n << " calls to now(), the min/avg/max observed delta was " << std::endl <<
        min_delta.count() << "/" << avg_delta.count() << "/" << max_delta.count() << " seconds, or " << std::endl <<
        min_ns << "/" << avg_ns<< "/" << max_ns << " nanoseconds." << std::endl;
}

