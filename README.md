# Hospital · gestão de consultas em C

Aplicação de terminal para cadastrar médicos e pacientes, organizar consultas e consultar relatórios. O projeto explora listas encadeadas, ponteiros, alocação dinâmica e a relação entre diferentes registros em C.

## Funcionalidades presentes no código

- **Médicos:** inclusão, listagem, busca por ID, atualização e exclusão.
- **Pacientes:** inclusão, listagem, busca por ID, atualização e exclusão.
- **Consultas:** cadastro com médico e paciente existentes, listagem, busca por número, atualização e exclusão.
- **Relatórios:** consultas por médico, paciente ou especialidade.

Os dados ficam somente na memória durante a execução. Encerrar o programa descarta os cadastros; não há banco de dados ou gravação em arquivos.

## Como compilar e executar

É necessário um compilador C, como GCC, disponível no terminal. Não há bibliotecas externas: o código usa `stdio.h`, `stdlib.h` e `string.h`.

```sh
git clone https://github.com/CaiouBS/Hospital.git
cd Hospital
```

No Linux ou macOS com GCC instalado:

```sh
gcc -std=c11 -Wall -Wextra -Wpedantic hospital.c -o hospital
./hospital
```

No Windows, com GCC instalado (por exemplo, via MinGW-w64), no PowerShell:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic hospital.c -o hospital.exe
.\hospital.exe
```

## Primeiro uso

O menu principal oferece:

```text
1. | Medicos
2. | Pacientes
3. | Consultas
4. | Relatorios
5. | Sair
```

Para experimentar o cadastro de um médico:

1. Escolha **1 — Medicos** e depois **1 — Incluir Medico**.
2. Digite um nome fictício, um ID numérico e uma especialidade.
3. Escolha **2 — Exibir Medicos** para conferir o registro.
4. Use **6 — Voltar** e **5 — Sair** para encerrar.

Para cadastrar uma consulta, primeiro cadastre um médico e um paciente. O programa pede o número da consulta, os IDs desses registros, horário (`HH:MM`), duração em minutos e data (`DD/MM/AAAA`). Os formatos são orientações de entrada; o programa ainda não os valida de forma completa.

## Organização e conceitos

O código está concentrado em [hospital.c](hospital.c).

| Estrutura | Responsabilidade |
| --- | --- |
| `Medico` / `ListaMedicos` | Registros com ID, nome e especialidade em uma lista encadeada. |
| `Paciente` / `ListaPacientes` | Registros de identificação e contato em uma lista encadeada. |
| `Consulta` / `ListaConsulta` | Registros de agendamento com ponteiros para o médico e o paciente. |

As operações percorrem as listas para localizar registros. As consultas compartilham os registros de médicos e pacientes por ponteiros, em vez de copiar seus dados.

## Estado atual e limitações

A versão atual serve para estudo e demonstração no terminal. Use dados fictícios.

- As entradas numéricas, os tamanhos dos textos e a unicidade dos identificadores ainda precisam de validação consistente.
- Há um `getchar()` extra no cadastro do paciente antes da leitura do endereço, que pode consumir seu primeiro caractere.
- Ao atualizar uma consulta, a busca pelo novo médico ou paciente começa nos registros associados à primeira consulta; registros anteriores nas listas podem não ser encontrados.
- A exclusão de médicos ou pacientes tenta remover as consultas relacionadas, mas acessa o ponteiro de uma consulta após liberá-la. Esse fluxo precisa de correção antes de ser usado como demonstração de exclusão em cascata.
- A opção **Sair** chama `exit(1)`: o terminal informa código de saída `1` mesmo no encerramento escolhido pelo usuário. A liberação completa das listas também precisa ser revista.

## Possíveis próximos passos

- Corrigir os fluxos de entrada, atualização e exclusão indicados acima.
- Separar entidades, operações e menus em módulos.
- Adicionar testes dos relacionamentos e da liberação de memória.
- Implementar persistência para manter os registros entre execuções.
