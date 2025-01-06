// FUNÇÃO PARA CARREGAR OS DADOS NA TABELA
function loadTableData() {
    const dataTable = document.getElementById('dataTable');
    const data = JSON.parse(localStorage.getItem('formData')) || [];

    // APAGAR A TABELA ANTES DE ADICIONAR OS NOVOS DADOS
    dataTable.innerHTML = `
        <tr class="tabela-main-header">
            <th><i class="fa-solid fa-trash"></i></th>
            <th>Nome</th>
            <th>Email</th>
            <th>Palavra-Passe</th>
            <th>Telemóvel</th>
            <th>CC</th>
            <th>Cidade</th>
            <th>Morada</th>
        </tr>
    `;

    // ADICIONAR AS LINHAS DA TABELA
    data.forEach((item, index) => {
        const row = document.createElement('tr');
        row.innerHTML = `
            <td><button onclick="removeData(${index})" class="tabelaBTN-remover"><i class="fa-solid fa-xmark"></i></button></td>
            <td>${item.nome}</td>
            <td>${item.email}</td>
            <td>${item.password}</td>
            <td>${item.tele}</td>
            <td>${item.bi}</td>
            <td>${item.cidade}</td>
            <td>${item.morada}</td>
        `;
        dataTable.appendChild(row);
    });
}

// FUNÇÃO PARA APAGAR DADOS DO LOCALSTORAGE
function removeData(index) {
    const data = JSON.parse(localStorage.getItem('formData')) || [];

    data.splice(index, 1); // APAGAR PELO INDICE

    localStorage.setItem('formData', JSON.stringify(data)); // ATUALIZAR O LOCALSTORAGE

    loadTableData(); // CARREGAR OUTRA VEZ OS DADOS NA TABELA
}

// FUNÇÃO PARA GUARDAR OS DADOS NO LOCALSTORAGE
function saveData(event) {
    event.preventDefault();

    // FAZ GET AOS DADOS DO FORMULÁRIO
    const form = document.getElementById('form');
    const newData = {
        nome: form.nome.value,
        email: form.email.value,
        password: form.password.value,
        tele: form.tele.value,
        bi: form.bi.value,
        cidade: form.cidade.value,
        morada: form.morada.value,
    };

    // FAZ GET AOS DADOS JÁ EXISTENTES NO LOCALSTORAGE
    const existingData = JSON.parse(localStorage.getItem('formData')) || [];
    existingData.push(newData);

    // GUARDA OS NOVOS DADOS NO LOCALSTORAGE
    localStorage.setItem('formData', JSON.stringify(existingData));

    // CARREGA OUTRA VEZ OS DADOS NA TABELA
    loadTableData();

    // APAGA OS DADOS DO FORMULÁRIO
    form.reset();
}

// ADICIONAR LISTENER PARA O BOTÃO DE SUBMIT DO FORMULÁRIO
document.getElementById('form').addEventListener('submit', saveData);

// CARREGAR DADOS NA TABELA QUANDO A PÁGINA CARREGA
document.addEventListener('DOMContentLoaded', loadTableData);
