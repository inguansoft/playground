
console.log('hello world');

const lambda_one = (firstName="hell", land="wo") => `${firstName} of ${land}`;

const lambda_two = (firstName, land) => `${firstName} of ${land}`;

sample = function (sample_A) {
    console.log(sample_A);
}

sample(lambda_one(undefined,'s'));

