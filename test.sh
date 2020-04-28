#!/bin/bash

echo "Content-type: text/html"
echo ""

echo '<html>'
echo '<head>'
echo '<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">'
echo '<title>Leap Year Validation</title>'
echo '</head>'
echo '<body>'
result=`./main 2000`
echo $result
echo '</body>'
echo '</html>'

exit 0
