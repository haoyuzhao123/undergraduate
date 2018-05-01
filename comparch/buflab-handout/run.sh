echo Haoyu Zhao, 2016012390
echo useerid: 2016012390
echo =========================================
echo now enters Level 0
cat level0.txt | ./hex2raw | ./bufbomb -u 2016012390
echo
echo now enters Level 1
cat level1.txt | ./hex2raw | ./bufbomb -u 2016012390
echo
echo now enters Level 2
cat level2.txt | ./hex2raw | ./bufbomb -u 2016012390
echo
echo now enters Level 3
cat level3.txt | ./hex2raw | ./bufbomb -u 2016012390
echo
echo now enters Level 4
cat level4.txt | ./hex2raw -n | ./bufbomb -n -u 2016012390
