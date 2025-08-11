#include <bits/stdc++.h>
using namespace std;

auto solve(/* params */) {
    /*
    SPEC:
    - Entradas:
    - Salidas:
    - Reglas/empates:
    - Edge cases:
    */
    // TODO: implementar
    return /* tipo */;
}

struct TestCase {
    tuple</* tipos entrada */> inp;
    /* tipo salida */ expected;
};

int main() {
    vector<TestCase> cases = {
        { make_tuple(/* ... */), /* expected */ },
        { make_tuple(/* ... */), /* expected */ },
        { make_tuple(/* ... */), /* expected */ },
    };

    int fails = 0;
    for (size_t i = 0; i < cases.size(); ++i) {
        auto [/* arg1, arg2, ... */] = cases[i].inp;
        auto got = solve(/* arg1, arg2, ... */);
        if (!(got == cases[i].expected)) {
            cerr << "FAIL case " << i+1 << "\n";
            fails++;
        }
    }
    if (fails) {
        cerr << fails << " test(s) failed\n";
        return 1;
    }
    cout << "OK\n";
}
