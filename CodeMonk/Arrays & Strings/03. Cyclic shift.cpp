#include <bits/stdc++.h>

using namespace std;

struct segment {

    int length, startPosition, endPosition;

    void reset() {
        this->length = 0;
        this->startPosition = 0;
        this->endPosition = 0;
    }
};

void findSegments(const string & str, const size_t & length, const char & element, vector<segment> &segmentInfoList)
{
    segment aSegment;
    aSegment.reset();

    size_t i;
    bool beforeSegment = false;

    for (i = 0; i < length; ++i)
    {
        if (str[i] == element)
        {
            // Special case
            if (beforeSegment == false)
            {
                aSegment.startPosition = i;
            }
            // Mandetory operation
            ++aSegment.length;
            beforeSegment = true;
        }
        else if (beforeSegment == true)
        {
            beforeSegment = false;
            aSegment.endPosition = (i - 1);
            segmentInfoList.push_back(aSegment);
            aSegment.reset();
        }
    }

    if (beforeSegment == true)
    {
        beforeSegment = false;
        aSegment.endPosition = (i - 1);
        segmentInfoList.push_back(aSegment);
    }
}

segment findMaxSegment(vector<segment> &segmentInfoList) {
    segment aSegment;

    aSegment = segmentInfoList.front();

    for (size_t i = 1; i < segmentInfoList.size(); ++i) {
        if (aSegment.length < segmentInfoList[i].length) {
            aSegment = segmentInfoList.at(i);
        }
    }

    return aSegment;
}

int main() {

    freopen("in.txt", "r", stdin);

    int test, i, len;
    unsigned long long int result, k, n;
    bool previousZeros, previousOnes;
    string str;
    vector < segment > segmentsOfZeros, segmentsOfOnes;
    segment aSegment, firstSegment, lastSegment, maxZerosSegment, maxOnesSegment;

    scanf("%d", &test);
    while(test--) {

        scanf("%llu %llu", &n, &k);
        cin >> str;

        segmentsOfZeros.clear();
        segmentsOfOnes.clear();
        previousOnes = previousZeros = false;
        result = 0;
        aSegment.reset();

        findSegments(str, n, '0', segmentsOfZeros);
        findSegments(str, n, '1', segmentsOfOnes);

        firstSegment = segmentsOfZeros.front();
        lastSegment = segmentsOfZeros.back();

        if (firstSegment.startPosition == 0 && lastSegment.endPosition == (n - 1)) {
            segmentsOfZeros[0].length += lastSegment.length;
            segmentsOfZeros.pop_back();
        }

        firstSegment = segmentsOfOnes.front();
        lastSegment = segmentsOfOnes.back();
        len = segmentsOfOnes.size();

        if (firstSegment.startPosition == 0 && lastSegment.endPosition == (n - 1)) {
            segmentsOfOnes[len - 1].length += firstSegment.length;
        }

        maxZerosSegment = findMaxSegment(segmentsOfZeros);
        maxOnesSegment = findMaxSegment(segmentsOfOnes);

        --k;

        if (maxZerosSegment.length == 1 && maxOnesSegment.length == 1) {
            result = 1;
            
            if (k > 0) {
                result += (unsigned long long int) (k * 2);
            }

        }
        else {
           result = maxOnesSegment.startPosition;

           if (k > 0) {
                result += (unsigned long long int) (k * n);
            }
        }
        
        printf("%llu\n", result);

    }

    return (0);
}