#include <iostream>
#include <vector>

using namespace std;

int main() {

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, C, P;
        cin >> N >> C >> P;
        vector<string> noun;
        vector<string> tv;
        vector<string> iv;
        vector<string> conj;

        for (int i = 0; i < N; ++i) {
            string str1, str2;
            cin >> str1 >> str2;
            if (str2[0] == 'n') noun.push_back(str1);
            if (str2[0] == 't') tv.push_back(str1);
            if (str2[0] == 'i') iv.push_back(str1);
            if (str2[0] == 'c') conj.push_back(str1);
        }

        int nouns = noun.size();
        int tvs = tv.size();
        int ivs = iv.size();
        int conjs = conj.size();

        // find the optimal number of
        // s1 - Sentences of type 1: noun+iv
        // s2 - Sentences of type 2: noun + tv + noun(s)
        // s3 - Sentences with conjunctions
        // nouns_with_commas - How many nouns we can add.
        int max_total_words = 0;
        int max_s1, max_s2, max_s3, max_nouns_with_commas;
        for (int s1 = 0; s1 <= min(ivs, nouns); ++s1) {
            int s2_possible = min(tvs, (nouns - s1) / 2);
            for (int s2 = 0; s2 <= s2_possible; ++s2) {
                // We have s1+s2 sentences.
                int stotal = s1 + s2;
                // Now, let's try connecting with conjunctions
                int s3 = min(conjs, stotal / 2);
                if (stotal - s3 > P) {  // Verify we have enough periods.
                    continue;
                }

                // How many nouns we can add with commas?
                // we need at least one sentence of type s1.
                int nouns_w_commas = 0;
                if (s2 > 0) {
                    nouns_w_commas = min(nouns - (s1 + 2 * s2), C);
                }
                int total_words = 2 * s1 + 3 * s2 + s3 + nouns_w_commas;
                if (total_words > max_total_words) {
                    max_total_words = total_words;
                    max_s1 = s1;
                    max_s2 = s2;
                    max_s3 = s3;
                    max_nouns_with_commas = nouns_w_commas;
                }
            }

        }
        // cout << "(max_words, max_s1, max_s2, max_s3, max_nouns_with_commas)=" << max_total_words << ", " << max_s1 << ", " << max_s2 << ", " << max_s3 << ", " << max_nouns_with_commas;
        cout << max_total_words << '\n';

        string out = "";
        if (max_total_words > 0) {
            // Assemble the sentences.
            vector<string> s1_2_vec, s3_vec;

            // vector<string> noun;
            // vector<string> tv;
            // vector<string> iv;
            // vector<string> conj;
            // find the optimal number of
            // s1 - Sentences of type 1: noun+iv
            // s2 - Sentences of type 2: noun + tv + noun(s)
            // s3 - Sentences with conjunctions
            // nouns_with_commas - How many nouns we can add.


            // Create s1 sentences
            for (int i = 0; i < max_s1; ++i) {
                s1_2_vec.push_back(noun.back() + " " + iv.back());
                noun.pop_back();
                iv.pop_back();
            }
            // Create s2 sentences
            for (int i = 0; i < max_s2; ++i) {
                string str;
                str = noun.back() + " " + tv.back() + " ";
                noun.pop_back();
                tv.pop_back();
                str += noun.back();
                noun.pop_back();
                s1_2_vec.push_back(str);
            }
            // Create sentence with all the nouns added by commas
            string str = s1_2_vec.back();
            s1_2_vec.pop_back();
            for (int i = 0; i < max_nouns_with_commas; ++i) {
                str += ", " + noun.back();
                noun.pop_back();
            }
            s1_2_vec.push_back(str);

            // Create s3 sentences
            for (int i = 0; i < max_s3; ++i) {
                string str;
                str = s1_2_vec.back() + " " + conj.back() + " ";
                s1_2_vec.pop_back();
                conj.pop_back();
                str += s1_2_vec.back();
                s1_2_vec.pop_back();
                s3_vec.push_back(str);
            }


            for (string s: s1_2_vec) {
                out += s + "." + " ";
            }
            for (string s: s3_vec) {
                out += s + "." + " ";
            }
            out.pop_back(); // get rid of the last element in the string
        }
        cout << out << '\n';

    }


}
/*
1
10 5 4
bessie noun
taught transitive-verb
flew intransitive-verb
elsie noun
farmer noun
john noun
and conjunction
and conjunction
nhoj noun
mooed intransitive-verb

Ans: 9, 2, 1, 1, 1


        */


/*
1
24 5 4
but conjunction
bessie noun
taught transitive-verb
flew intransitive-verb
elsie noun
farmer noun
john noun
and conjunction
and conjunction
nhoj noun
mooed intransitive-verb
bob noun
impressed transitive-verb
cow noun
impressed transitive-verb
leaped intransitive-verb
elsie noun
bella noun
buttercup noun
pushed transitive-verb
mooed intransitive-verb
envy noun
john noun
nhoj noun

Ans:
23, 3, 4, 3, 2

 */