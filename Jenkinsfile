pipeline {

     parameters {
        string(name: 'year', defaultValue: '', description: 'Enter Year to check whether it is a leap year')
	}
    
   
    agent {label "master"}
    
    stages {
    
        stage ('Checkout') {
		   steps{
              // validate if entered parameter is numeric
              sh '''
               if     [ -z "${year##*[!0-9]*}" ]; 
                then   echo "Not a vaild year to test for leap year"
                exit 1
                fi
              '''
			  cleanWs()
              checkout([$class: 'GitSCM', branches: [[name: '*/master']], doGenerateSubmoduleConfigurations: false, extensions: [], submoduleCfg: [], userRemoteConfigs: [[url: 'https://github.com/ziatahir/cpp_leap_year.git']]])
              }
		   }
           
         stage('Static code Analysis') {
           steps {
		      echo "static code analysis using cppcheck tool"
              //generate SCAReport.xml file containg report
              sh '''
                 cppcheck --enable=all --inconclusive --xml-version=2 -v  --output-file=SCAReport.xml main.cpp
                 errorCount=$(grep error SCAReport.xml | wc -l)
                 echo $errorCount
                 if [ $errorCount -gt 3 ]
			       then 
			       echo "There is/are code review error[s]...Please look in the below xml for details -"
			       more SCAReport.xml
			       exit 1
			     else
			        echo "There is no code review error ... proceeding to next unit testing ..."
			     fi 
			     
			  '''
             }
        }
        
         stage('Unit Testing') {
           steps {
		      echo "unit testing using boost tool"
              //generate a.out , execute a.out to perform actual unit test 
              sh '''
                 g++ unitTest.cpp -DBOOST_TEST_DYN_LINK -lboost_unit_test_framework
                 ./a.out
			  '''
             }
        }
            
          
	
        stage('Compile') {
           steps {
		      echo "Compiling using g++ complier"
              sh '''
                 # complie
                 g++ -c main.cpp validateYear.cpp
                 # link multiple object file
                 g++ -o main main.o validateYear.o 
                 # list files
                 ls -ltr
			  '''
             }
        }
        
        stage('Packaging Nexus') {
           steps {
		      echo "Upload to Nexus"
              sh '''
                echo "Upload to Nexus"
			  '''
             }
        }
        
        stage('Deploy') {
           steps {
		      echo "validate leap year"
              sh '''
                 ./main $year 
                 
cat <<EOF > displayYear.sh
#!/bin/bash

echo ""

echo '<html>'
echo '<head>'
echo '<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">'
echo '<title>Leap Year Validation</title>'
echo '</head>'
echo '<body>'
echo `./main $year`
echo '</body>'
echo '</html>'

exit 0
EOF
              chmod 755 displayYear.sh
              #generating index.html file
              ./displayYear.sh > index.html
			  '''
              // build docker image and push to registery
              script{
               customImage = docker.build("cpp_apache")
			  // docker.withRegistry('https://registry.hub.docker.com', 'docker_hub') {
              // customImage.push()
               // execting docker container
                 sh '''
                   docker run -d -p 8085:80 cpp_apache:latest apachectl -D FOREGROUND
                  '''
               
		       }
              } 
              
              
             }
        
       
        
    }
    
}
