// Lab 13: Debugging and Testing
// EECS 348 - Fall 2025
//
// This program demonstrates the distinction between fault, error state, and failure
// for a simple attendance-based failing rule.
//
// Fault: the loop in fail_lecture_buggy starts from i = 1 instead of i = 0,
//        so it ignores the first lecture's attendance.
//
// Q3 test: executes the fault but no error state (first lecture is present).
// Q4 test: error state but no failure.
// Q5 test: error state and failure.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// BUGGY implementation (as given in the lab)
bool fail_lecture_buggy(const vector<int>& attendance_records) {
    int absentcount = 0;
    for (int i = 1; i < (int)attendance_records.size(); ++i) {
        absentcount += (attendance_records[i] == 0);
    }
    return absentcount >= 3;
}

// CORRECT implementation (specification)
bool fail_lecture_correct(const vector<int>& attendance_records) {
    int absentcount = 0;
    for (int i = 0; i < (int)attendance_records.size(); ++i) {
        absentcount += (attendance_records[i] == 0);
    }
    return absentcount >= 3;
}

// Helper to print a vector as [a, b, c, ...]
void print_record(const vector<int>& rec) {
    cout << "[";
    for (size_t i = 0; i < rec.size(); ++i) {
        cout << rec[i];
        if (i + 1 < rec.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    // Q3: executes fault, no error state, no failure
    vector<int> tc_q3 = {1, 0, 0, 1, 1, 1, 1, 1, 1, 1};

    // Q4: error state but no failure
    vector<int> tc_q4 = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1};

    // Q5: error state and failure
    vector<int> tc_q5 = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};

    vector<vector<int>> tests = {tc_q3, tc_q4, tc_q5};
    const char* labels[] = {"Q3", "Q4", "Q5"};

    for (int i = 0; i < 3; ++i) {
        cout << labels[i] << " test case: ";
        print_record(tests[i]);
        cout << endl;

        bool expected = fail_lecture_correct(tests[i]);
        bool actual   = fail_lecture_buggy(tests[i]);

        cout << "  Expected (correct spec): " << (expected ? "FAIL" : "PASS") << endl;
        cout << "  Actual   (buggy code)  : " << (actual   ? "FAIL" : "PASS") << endl;
        cout << endl;
    }

    return 0;
}
