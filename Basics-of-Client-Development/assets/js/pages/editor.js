'use strict';

const editorMenu = document.getElementById('editor-menu');
const editorField = document.getElementById('editor-field');

const props = []; // TODO

const PropsController = {
  color: {
    default: 'black',
    highlight: 'blue',
  },
  highlight: function (event) {
    event.target.style.color = this.color.highlight;
  },
  reset: function (event) {
    event.target.style.color = this.color.default;
  },
  add: function (event) {
    console.log({ target: event.target }); // TODO
    this.reset(event);
  },
};

const ActionsController = {
  undo: function () {
    console.log({ undo: true }); // TODO
  },
  redo: function () {
    console.log({ redo: true }); // TODO
  },
  clean: function () {
    console.log({ clean: true }); // TODO
  },
  onClick: function (event) {
    const action = event.target.dataset.action;
    if (!action) return;
    this[action]();
  },
};

const StatisticsController = {
  statistics: [],
  collect: function (event) {
    const { target } = event;
    const info = this.statistics.find(entry => entry.target === target);
    if (info) {
      info.clicks++;
      return;
    }
    this.statistics.push({
      target,
      clicks: 1,
    });
  },
  listen: function (...elements) {
    elements.forEach(element =>
      element.addEventListener('click', event => this.collect(event)));
  },
  print: function () {
    let result = 'Statistics\n';
    for (const { target, clicks } of this.statistics) {
      result += `${target.innerHTML}: clicks=${clicks}\n`;
    }
    alert(result);
  },
};

const KeyboardController = {
  bindings: {
    CtrlU: () => StatisticsController.print(),
  },
  handleEvent: function (event) {
    const method = this[event.type];
    if (!method) return;
    method.bind(this, event)();
  },
  keypress: function (event) {
    if (event.ctrlKey && event.key == 'u') {
      this.bindings.CtrlU();
    }
  },
};

StatisticsController.listen(
  editorMenu,
  editorField,
);

document.addEventListener('keypress', KeyboardController);
