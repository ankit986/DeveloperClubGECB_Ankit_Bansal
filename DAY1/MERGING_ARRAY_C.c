#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int compareMeetingsByStartTime(const void *meetingA, const void *meetingB)
{
    const Meeting *a = (const Meeting *)meetingA;
    const Meeting *b = (const Meeting *)meetingB;
    return (a->startTime - b->startTime);
}

size_t mergeRanges(const Meeting *input, size_t inputLength,
                   Meeting *output, size_t maxOutputLength)
{
    Meeting *sortedInput;
    size_t i;
    size_t currentOutputLength = 0;

    // output array must be large enough to hold all input meetings
    assert(maxOutputLength >= inputLength);

    // create new input to sort (prevent modifying input)
    sortedInput = malloc(sizeof(Meeting) * inputLength);
    assert(sortedInput != NULL);
    memcpy(sortedInput, input, sizeof(Meeting) * inputLength);

    // sort by start time
    qsort(sortedInput, inputLength, sizeof(Meeting), compareMeetingsByStartTime);

    // initialize output with the earliest meeting
    output[0] = sortedInput[0];
    currentOutputLength++;

    // merge iteration
    for (i = 0; i < inputLength; i++) {
        Meeting *currentMeeting = &sortedInput[i];
        Meeting *lastMergedMeeting = &output[currentOutputLength - 1];

        // if the current meeting overlaps with the last merged meeting, use the
        // later end time of the two
        if (currentMeeting->startTime <= lastMergedMeeting->endTime) {
            lastMergedMeeting->endTime = MAX(lastMergedMeeting->endTime,
                                             currentMeeting->endTime);

        // add the current meeting since it doesn't overlap
        }
        else {
            currentOutputLength++;
            output[currentOutputLength - 1] = *currentMeeting;
        }
    }

    // free memory allocation
    free(sortedInput);

    return currentOutputLength;
}
