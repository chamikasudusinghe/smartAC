var boatRef = firebase.database().ref('ac');

document.getElementById('boatFrom').addEventListener('submit', submitForm);

function submitForm(e){
  e.preventDefault();

  var id = getInputVal('status');

  loadBoat(id);

  document.querySelector('.alert').style.display = 'block';

  setTimeout(function(){
    document.querySelector('.alert').style.display = 'none';
  },3000);

  document.getElementById('boatFrom').reset();
}

function getInputVal(id){
  return document.getElementById(id).value;
}

function loadBoat(status){
  boatRef.set({
    id: status,
  });

}
