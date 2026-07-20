# 📖 Guia de Uso - Template de Algoritmos

## 🎯 Qual Template Usar?

Agora existem **3 versões** do template de algoritmos. Escolha a que melhor funciona no seu Obsidian:

### 🥇 **Opção 1: Template Simples (RECOMENDADA)**
**Arquivo:** `Algoritmo - Template (Simples).md`

**Características:**
- ✅ Mais estável e compatível
- ✅ Cursores fora dos links `[[...]]`
- ❌ Sem movimentação automática (você move manualmente para `/Algoritmos/`)
- 📌 **Use esta se você teve erro de "template parsing error"**

**Como usar:**
1. `Ctrl + P` → "Templater: Create new note from template"
2. Selecione: **"Algoritmo - Template (Simples)"**
3. Digite o nome (ex: "Floyd-Warshall")
4. **Após preencher, mova o arquivo manualmente para `/Algoritmos/`**

---

### 🥈 **Opção 2: Template Híbrida**
**Arquivo:** `Algoritmo - Template (Hibrida).md`

**Características:**
- ✅ Movimentação automática para `/Algoritmos/`
- ✅ Cursores fora dos links (mais estável)
- ⚠️ Você adiciona os `[[...]]` manualmente depois de preencher

**Como usar:**
1. `Ctrl + P` → "Templater: Create new note from template"
2. Selecione: **"Algoritmo - Template (Hibrida)"**
3. Digite o nome (ex: "Floyd-Warshall")
4. Preencha os cursores (MOC, Pré-requisitos, Autor)
5. **Adicione os colchetes `[[...]]` manualmente nos links**

---

### 🥉 **Opção 3: Template Com Move**
**Arquivo:** `Algoritmo - Template (Com Move).md`

**Características:**
- ✅ Movimentação automática para `/Algoritmos/`
- ✅ Links já formatados com `[[...]]`
- ⚠️ Cursores **dentro** dos links (pode dar parsing error em alguns casos)
- 📌 **Teste esta versão apenas se as outras 2 não atenderem suas necessidades**

**Como usar:**
1. `Ctrl + P` → "Templater: Create new note from template"
2. Selecione: **"Algoritmo - Template (Com Move)"**
3. Digite o nome (ex: "Floyd-Warshall")
4. Preencha os cursores diretamente

---

## 🧪 Ordem de Teste Recomendada

Se você teve problemas com templates antes, teste nesta ordem:

1. **Primeiro:** Template Simples (menos features, mais estável)
2. **Se funcionou:** Tente a Template Híbrida (move automático + estável)
3. **Se ainda funcionou:** Tente a Template Com Move (todas as features)

**Use a versão que funcionar melhor no seu setup do Obsidian!**

---

## 🎯 Como Usar o Template Corretamente

### Método 1: Criar Nova Nota com Template (RECOMENDADO)

1. **Pressione `Ctrl + P`** (ou `Cmd + P` no Mac)
2. Digite: **"Templater: Create new note from template"**
3. Selecione: **"Algoritmo - Template"**
4. Digite o nome do algoritmo (ex: "Floyd-Warshall")
5. Pressione Enter

✅ **O template será aplicado automaticamente e o arquivo será movido para a pasta `/Algoritmos/`**

---

### Método 2: Inserir Template em Arquivo Existente

1. Crie um novo arquivo na raiz ou onde preferir
2. Dê um nome ao arquivo (ex: "Floyd-Warshall")
3. **Pressione `Ctrl + P`**
4. Digite: **"Templater: Open Insert Template modal"**
5. Selecione: **"Algoritmo - Template"**

✅ **O template será inserido e o arquivo será movido automaticamente para `/Algoritmos/`**

---

## 🔄 O Que Acontece Quando Você Aplica o Template?

### 1. **Movimentação Automática**
```
<%* await tp.file.move("/Algoritmos/" + tp.file.title) %>
```
- O arquivo é **automaticamente movido** para a pasta `Algoritmos/`
- O nome do arquivo é preservado
- **Nota:** Se o arquivo já existir na pasta, pode dar erro

### 2. **Frontmatter Preenchido Automaticamente**
```yaml
---
aliases: []
tags: #cp #algoritmo #obi #icpc
data_criacao: 2026-07-20  # ← Data atual inserida automaticamente
status: a_revisar
---
```

### 3. **Título com o Nome do Arquivo**
```markdown
# 📚 Floyd-Warshall  # ← Nome do arquivo inserido automaticamente
```

### 4. **Cursores para Navegação Rápida**
Após aplicar o template, você verá 3 cursores numerados:

- **Cursor 1:** MOC (Map of Content) - Link para o mapa relacionado
- **Cursor 2:** Pré-requisitos - Links para conceitos necessários
- **Cursor 3:** Autor do algoritmo

**Para navegar entre cursores:**
- Pressione `Tab` (se configurado no Templater)
- Ou use `Ctrl + F` para buscar `tp.file.cursor` e pular manualmente

---

## ⚙️ Configurações Importantes do Templater

Verifique suas configurações em: **Settings → Templater**

### Configurações Atuais:
- ✅ **Template folder:** `z-templates` (correto)
- ⚠️ **Trigger on file creation:** `false` (desabilitado)
- ⚠️ **Auto jump to cursor:** `false` (desabilitado)

### Recomendações:
1. **Ativar "Auto jump to cursor":**
   - Settings → Templater → "Auto jump to cursor" → `ON`
   - Isso fará o cursor pular automaticamente para o primeiro `tp.file.cursor(1)`

2. **Opcional - Trigger automático:**
   - Settings → Templater → "Trigger on file creation" → `ON`
   - Settings → Templater → "Folder Templates"
   - Adicionar: `Algoritmos/` → `Algoritmo - Template`
   - **Efeito:** Qualquer arquivo criado em `Algoritmos/` aplicará o template automaticamente

---

## ❌ Erros Comuns e Soluções

### Problema 1: "Template Parsing Error" ou "Template Error"

**Causa:** Comandos Templater conflitando com sintaxe do Obsidian (cursores dentro de links `[[...]]`)

**Solução:**
1. **Use o Template Simples ou Híbrida** (versões mais estáveis)
2. Evite usar "Template Com Move" se você recebeu este erro
3. Se o erro persistir, verifique se o plugin Templater está atualizado

---

### Problema 2: "Os comandos `<% %>` aparecem literalmente no arquivo"

**Causa:** Você usou o comando errado para inserir o template

❌ **ERRADO:** "Templates: Insert template" (comando nativo do Obsidian)
✅ **CORRETO:** "Templater: Open Insert Template modal" (comando do plugin Templater)

**Solução:** Delete o conteúdo, e use o comando correto do Templater

---

### Problema 3: "Erro ao mover arquivo"

**Causa:** Já existe um arquivo com o mesmo nome em `/Algoritmos/`

**Solução:**
1. Renomeie o arquivo atual antes de aplicar o template
2. Ou delete o arquivo duplicado em `/Algoritmos/`
3. Reaplique o template
4. **Ou use o Template Simples** que não move automaticamente

---

### Problema 4: "Cursores não funcionam / não navego automaticamente"

**Causa:** A opção "Auto jump to cursor" está desabilitada

**Solução:**
1. Settings → Templater
2. Ative: **"Auto jump to cursor"**
3. Ou navegue manualmente usando `Tab` após aplicar o template

---

## 📝 Exemplo Prático: Criar "Floyd-Warshall"

### Passo a passo:

1. `Ctrl + P` → "Templater: Create new note from template"
2. Selecione: "Algoritmo - Template"
3. Digite: "Floyd-Warshall"
4. Pressione Enter

**Resultado:**
```markdown
---
aliases: []
tags: #cp #algoritmo #obi #icpc
data_criacao: 2026-07-20
status: a_revisar
---

# 📚 Floyd-Warshall

**MOC:** [[___]]  ← Cursor 1: Preencha com MOC relacionado (ex: [[MOC - Grafos]])
**Pré-requisitos:** [[___]]  ← Cursor 2: Preencha pré-requisitos (ex: [[DP]])
**Autor:** ___  ← Cursor 3: Nome do autor (ex: Robert Floyd)
```

5. Preencha os campos com Tab ou clicando:
   - Cursor 1: `MOC - Grafos`
   - Cursor 2: `DP`, `Grafos`
   - Cursor 3: `Robert Floyd e Stephen Warshall`

6. Continue preenchendo o resto do template conforme necessário

---

## 🎓 Dicas Extras

### 1. **Aliases**
Adicione aliases manualmente no frontmatter para facilitar busca:
```yaml
aliases: [Floyd-Warshall, Caminho Mínimo, APSP]
```

### 2. **Tags Específicas**
Adicione tags específicas além das padrão:
```yaml
tags: #cp #algoritmo #obi #icpc #grafos #dp
```

### 3. **MOCs Múltiplos**
Você pode linkar múltiplos MOCs:
```markdown
**MOC:** [[MOC - Grafos]] | [[MOC - Programação Dinâmica]]
```

### 4. **Verificar o Template**
Se quiser ver o template original sem aplicá-lo:
- Vá em: `z-templates/Algoritmo - Template.md`
- Abra em modo de leitura ou edição

---

## ✅ Checklist Rápido

Antes de usar o template, verifique:

- [ ] Plugin **Templater** está instalado e ativado
- [ ] Pasta de templates está configurada: `z-templates`
- [ ] Você está usando o comando **"Templater: ..."** (não "Templates: ...")
- [ ] O nome do arquivo não contém caracteres especiais (evite `/`, `\`, `:`, etc)
- [ ] Não existe arquivo duplicado na pasta `/Algoritmos/`

---

## 🆘 Precisa de Ajuda?

Se o template ainda não funcionar:

1. Verifique se o plugin Templater está ativo: Settings → Community Plugins
2. Recarregue o Obsidian: `Ctrl + R`
3. Teste criar um arquivo simples primeiro para verificar se o Templater funciona
4. Verifique o console: `Ctrl + Shift + I` (procure por erros em vermelho)

---

**Última atualização:** 2026-07-20
