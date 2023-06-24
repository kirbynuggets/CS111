#include <stdio.h>

int subjectMarks(int * ptr) {
  int lowest = 0, highest = 100, noOfStud = 50;

  for (int i = 0; i < noOfStud; i++) {
    int num = (rand() % (highest - lowest + 1)) + lowest;
    *(ptr + i) = num;
    //  printf("%d ",*(ptr+i));
  }
  printf("\n");
}

void maxMarks(int * ptr) {
  int max_marks = * ptr;
  for (int i = 0; i < 50; i++) {
    if (max_marks < * (ptr + i))
      max_marks = * (ptr + i);
  }
  printf("Max marks in Hindi are- %d \n", max_marks);
}
void minMarks(int * ptr) {
  int min_marks = * ptr;
  for (int i = 0; i < 50; i++) {
    if (min_marks > * (ptr + i))
      min_marks = * (ptr + i);
  }
  printf("Min marks in English are- %d \n", min_marks);
}

void mathGradeA(int * mathMarks) {
  int count_A = 0;
  for (int i = 0; i < 50; i++) {
    if ( * (mathMarks + i) >= 90) {

      count_A++;
    }
  }
  printf("Number of As in mathematics %d \n", count_A);
}

void count_students_failed(int * mathMarks, int * engMarks, int * sciMarks, int * hindiMarks) {
  int count = 0;
  for (int i = 0; i < 50; i++) {
    if (( * (mathMarks + i) <= 32) && ( * (engMarks + i) <= 32) && ( * (sciMarks + i) <= 32) && ( * (hindiMarks + i) <= 32))
      count++;
  }
  printf("Number of students who failed - %d \n", count);
}
double sumAvg = 0;;
void subjectWiseMarks(int * marksPerSub) {
  int marksSum = 0;
  for (int i = 0; i < 50; i++) {
    marksSum += * (marksPerSub + i);
  }

  double subwiseClassAvg = marksSum / 50.0;
  sumAvg += subwiseClassAvg;
  printf("%f \n", subwiseClassAvg);
}

void studentwisePercentage(int * mathMarks, int * engMarks, int * sciMarks, int * hindiMarks) {
  int totalMarks = 0;
  for (int i = 0; i < 50; i++) {
    int totalMarks = * (mathMarks + i) + * (engMarks + i) + * (sciMarks + i) + * (hindiMarks + i);
    double percentage = (totalMarks * 100) / 400.0;
    printf("percentage of %dth student is %f \n", (i + 1), percentage);
  }
}

void main() {

  int * mathMarks = calloc(50, sizeof(int));
  subjectMarks(mathMarks);
  int * engMarks = calloc(50, sizeof(int));
  subjectMarks(engMarks);
  int * sciMarks = calloc(50, sizeof(int));
  subjectMarks(sciMarks);
  int * hindiMarks = calloc(50, sizeof(int));
  subjectMarks(hindiMarks);
  mathGradeA(mathMarks);
  maxMarks(engMarks);
  minMarks(hindiMarks);
  count_students_failed(mathMarks, engMarks, sciMarks, hindiMarks);
  printf("Avg of Math ");
  subjectWiseMarks(mathMarks);
  printf("Avg of English  ");
  subjectWiseMarks(engMarks);
  printf("Avg of Hindi  ");
  subjectWiseMarks(hindiMarks);
  printf("science average");
  subjectWiseMarks(sciMarks);
  printf("Class average %f \n", sumAvg / 4.00);
  studentwisePercentage(mathMarks, engMarks, sciMarks, hindiMarks);
}
