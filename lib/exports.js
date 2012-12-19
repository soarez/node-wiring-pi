function merge(obj, tgt) {
  for(var p in obj)
    if (obj.hasOwnProperty(p))
      tgt[p] = obj[p];
}

var c = require('../build/Release/wpi');

exports = {
  VERSION: require('../package').version
};

merge(c, exports);

module.exports = exports;
