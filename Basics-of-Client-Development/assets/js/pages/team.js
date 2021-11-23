'use strict';

const teamContainer = document.getElementById('team-container');
const surveyButton = document.getElementById('survey-button');
const goGitHubButton = document.getElementById('go-github-button');

const random = ({ min = 0, max }) =>
  Math.floor(Math.random() * (Math.floor(max) - Math.ceil(min))) + Math.ceil(min);

const TeamMember = (firstname, lastname, position = 'Minor Works') =>
  ({ firstname, lastname, position });

const team = [
  TeamMember('Yehor', 'Bublyk', 'Chief Executive Officer'),
  TeamMember('Yehor', 'Bublyk', 'Chief Technical Officer'),
  TeamMember('Yehor', 'Bublyk', 'Project Owner'),
  TeamMember('Yehor', 'Bublyk', 'Project Manager'),
  TeamMember('Yehor', 'Bublyk', 'Team Lead'),
  TeamMember('Yehor', 'Bublyk', 'Senior Front-end Engineer'),
  TeamMember('Yehor', 'Bublyk', 'Senior Back-end Engineer'),
  TeamMember('Yehor', 'Bublyk', 'Senior QA Engineer'),
  TeamMember('Yehor', 'Bublyk', 'DevOps'),
  TeamMember('Yehor', 'Bublyk'),
];

const pickRandomColor = () => {
  const colors = [
    '#FF0000',
    '#FF7F00',
    '#FFFF00',
    '#00FF00',
    '#0000FF',
    '#2E2B5F',
    '#8B00FF',
  ];
  return colors[random({ max: colors.length })];
};

const fillTeamContainer = () => {
  const ul = document.createElement('ul');
  ul.style.listStyleType = 'none';
  ul.style.paddingLeft = '0';
  for (const index in team) {
    const member = team[index];
    const li = document.createElement('li');
    li.innerHTML =
      `
        <a href="" onclick="showTeamMemberInformation(${index})">
          ${member.position}
        </a>
      `;
    ul.appendChild(li);
  }
  teamContainer.appendChild(ul);
};

const showTeamMemberInformation = index => {
  const member = team[index];
  alert(member.firstname + ' ' + member.lastname + ' | ' + member.position);
};

const party = () => {
  const positions = teamContainer.querySelectorAll('a');
  const defaultValues = {
    color: positions[0].style.color,
    background: document.body.style.backgroundColor,
  };
  const changeColorInterval = setInterval(() => {
    positions.forEach(entry => entry.style.color = pickRandomColor());
  }, 500);
  const changeBackgroundInterval = setInterval(() => {
    document.body.style.backgroundColor = pickRandomColor();
  }, 500);
  setTimeout(() => {
    clearInterval(changeColorInterval);
    clearInterval(changeBackgroundInterval);
    positions.forEach(entry => entry.style.color = defaultValues.color);
    document.body.style.backgroundColor = defaultValues.background;
  }, 5000);
};

const printSurveyResult = CV => {
  const print = {
    name: `Name: ${CV.name}\n`,
    email: `Email: ${CV.email}\n`,
    position: `Position: ${CV.position}\n`,
    experience: `Experience: ${CV.experience}\n`,
    english: `English: ${CV.english}\n`,
    additional: `Additional: ${CV.additional}\n`,
  };
  let result = '';
  for (const key in print) {
    const entry = print[key];
    result += entry;
  }
  alert(result);
};

const processSurveyResult = CV => {
  const isExperienceSuitable = CV.experience >= 1;
  const isEnglishSuitable = CV.english >= 'B1';
  if (isExperienceSuitable && isEnglishSuitable) {
    alert('Congratulations! You are accepted into our team :)');
    party();
  } else {
    alert('Thanks for your CV, we will call you later.');
  }
};

const processSurvey = () => {
  const englishLevel = ['A1', 'A2', 'B1', 'B2', 'C1', 'C2'];
  alert('Hello! We need ask some questions to fill your CV information.');
  const name = prompt('Enter your name:');
  const email = prompt('Enter email address:');
  const position = prompt('What position are you applying for?');
  const experience = prompt('How much years of experience do you have?');
  const english = prompt(`Your english level (${englishLevel.join(', ')})?`);
  const additional = prompt(`Additional information (GitHub, Skills...):`);
  const CV = { name, email, position, experience, english, additional };
  const isPrintResult = confirm('Print result?');
  if (isPrintResult) printSurveyResult(CV);
  alert('Your CV accepted. Please wait, we are discussing your CV...');
  setTimeout(processSurveyResult.bind(null, CV), 3000);
};

const goGitHub = () => {
  location.href = 'https://github.com/yehorbk';
};

const init = () => {
  fillTeamContainer();
  surveyButton.onclick = processSurvey;
  goGitHubButton.onclick = goGitHub;
};
