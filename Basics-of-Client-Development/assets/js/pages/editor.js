'use strict';

const Prop = (x, y, image) => ({
  x,
  y,
  width: image.width,
  height: image.height,
  image,
});

const editorMenu = document.getElementById('editor-menu');
const editorField = document.getElementById('editor-field');

const context = editorField.getContext('2d');

const images = (() => {
  const table = new Image(100, 50);
  table.src = '../assets/images/table.png';
  const computer = new Image(60, 30);
  computer.src = '../assets/images/computer.png';
  const window = new Image(80, 80);
  window.src = '../assets/images/window.png';
  const cabinet = new Image(200, 100);
  cabinet.src = '../assets/images/cabinet.png';
  return {
    table: Prop(0, 0, table),
    computer: Prop(0, 0, computer),
    window: Prop(0, 0, window),
    cabinet: Prop(0, 0, cabinet),
  };
})();

const props = [];
const removed = [];

const Field = (() => {
  const rect = editorField.getBoundingClientRect();
  const x = rect.left;
  const y = rect.top;
  const width = editorField.width;
  const height = editorField.height;
  const clean = () => {
    context.clearRect(0, 0, width, height);
  };
  const draw = prop => {
    context.drawImage(prop.image, prop.x, prop.y, prop.width, prop.height);
  };
  const drawAll = () => {
    clean();
    for (const prop of props) {
      context.drawImage(prop.image, prop.x, prop.y, prop.width, prop.height);
    }
  }
  return {
    x,
    y,
    width,
    height,
    clean,
    draw,
    drawAll,
  };
})();

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
    this.reset(event);
    const name = event.target.dataset.prop;
    if (!name) return;
    const prop = images[name];
    const copy = Prop(prop.x, prop.y, prop.image);
    Field.draw(copy);
    props.push(copy);
  },
};

const ActionsController = {
  undo: function () {
    if (props.length === 0) return;
    removed.push(props.pop());
    Field.drawAll();
  },
  redo: function () {
    if (removed.length === 0) return;
    props.push(removed.pop());
    Field.drawAll();
  },
  clean: function () {
    props.splice(0, props.length);
    removed.splice(0, removed.length);
    Field.drawAll();
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

const MouseController = {
  styles: {
    LI: {
      hover: {
        color: '#0088ff',
      },
      base: {
        color: 'black',
      },
    }
  },
  prop: null,
  handleEvent: function (event) {
    const method = this[event.type];
    if (!method) return;
    method.bind(this, event)();
  },
  mouseover: function (event) {
    const element = event.target;
    const styles = this.styles[element.nodeName];
    if (!styles) return;
    for (const key of Object.keys(styles.hover)) {
      element.style[key] = styles.hover[key];
    }
  },
  mouseout: function (event) {
    const element = event.target;
    const styles = this.styles[element.nodeName];
    if (!styles) return;
    for (const key of Object.keys(styles.base)) {
      element.style[key] = styles.base[key];
    }
  },
  mousedown: function (event) {
    const x = event.pageX - Field.x;
    const y = event.pageY - Field.y;
    for (const prop of props.reverse()) {
      const horizontal = (x >= prop.x && x <= prop.x + prop.width);
      const vertical = (y >= prop.y && y <= prop.y + prop.height);
      if (horizontal && vertical) {
        this.prop = prop;
        return;
      }
    }
  },
  mousemove: function (event) {
    if (!this.prop) return;
    this.prop.x = event.pageX - Field.x;
    this.prop.y = event.pageY - Field.y;
    Field.drawAll();
  },
  mouseup: function (event) {
    this.prop = null;
  },
}

StatisticsController.listen(
  editorMenu,
  editorField,
);

document.addEventListener('keypress', KeyboardController);
document.addEventListener('mouseover', MouseController);
document.addEventListener('mouseout', MouseController);
document.addEventListener('mousedown', MouseController);
document.addEventListener('mousemove', MouseController);
document.addEventListener('mouseup', MouseController);
