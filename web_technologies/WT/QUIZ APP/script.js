let questions = [];

fetch("questions.xml")
.then(response => response.text())
.then(data => {

    let parser = new DOMParser();
    let xml = parser.parseFromString(data,"text/xml");

    let q = xml.getElementsByTagName("question");

    let quizDiv = document.getElementById("quiz");

    for(let i=0;i<q.length;i++){

        let text = q[i].getElementsByTagName("text")[0].textContent;
        let options = q[i].getElementsByTagName("option");
        let ans = q[i].getElementsByTagName("answer")[0].textContent;

        questions.push(ans);

        let html = `<div class="question">
                    <p>${i+1}. ${text}</p>`;

        for(let j=0;j<options.length;j++){
            html += `<input type="radio" name="q${i}" value="${j}">
                     ${options[j].textContent}<br>`;
        }

        html += `</div>`;

        quizDiv.innerHTML += html;
    }
});

function submitQuiz(){

    let score = 0;

    for(let i=0;i<questions.length;i++){

        let selected = document.querySelector(`input[name="q${i}"]:checked`);

        if(selected && selected.value == questions[i]){
            score++;
        }
    }

    document.getElementById("result").innerHTML =
        "Your Score: " + score + " / " + questions.length;
}