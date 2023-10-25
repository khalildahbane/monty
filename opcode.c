
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}

/**
 * _pall - Prints all the elements of a dlistint_t list
 * @top: Head of double list
 * @line_number: Line num
 * Return: None
 */
void _pall(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int x;

	(void)line_number;
	for (x = 0; current; x++)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	fflush(stdout);
}

/**
 * _pint -  Prints the value at begining of stack
 * @top: Head of double list
 * @line_number: Line num
 * Return: None
 */
void _pint(stack_t **top, unsigned int line_number)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*top)->n);
	fflush(stdout);
}

/**
 * _pop - Removes the first element of the stack
 * @top: Head of double list
 * @line_number: Line num
 * Return: None
 */
void _pop(stack_t **top, unsigned int line_number)
{

	if (!*top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->next == NULL)
	{
		free(*top);
		*top = NULL;
	}
	else
	{
		*top = (*top)->next;
		free((*top)->prev);
		(*top)->prev = NULL;
	}
}

/**
 * _swap - Swaps the first two elements of the stack
 * @top: Head of double list
 * @line_number: Line num
 * Return: None
 */
void _swap(stack_t **top, unsigned int line_number)
{
	stack_t *tmp1;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	tmp1 = *top;
	tmp1->prev = tmp1->next;
	if ((*top)->next->next == NULL)
		tmp1->next = NULL;
	else
	{
		tmp1->next = tmp1->next->next;
		tmp1->next->prev = *top;
	}
	*top = tmp1->prev;
	(*top)->prev = NULL;
	(*top)->next = tmp1;
}

/**
 * _add - Adds the first two elements of the stack
 * @top: Head of double list
 * @line_number: Line num
 * Return: None
 */
void _add(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n += value;
}

/**
 * _nop - Doesn’t do anything
 * @top: Head of double list
 * @line_number: Line num
 * Return: None
 */
void _nop(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;
}

/**
 * _sub - Subtracts the first element of the stack from the second
 * @top: Head of double list
 * @line_number: line num
 * Return: None
 */
void _sub(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n -= value;
}

/**
 * _div - Divides the second top element of stack by the first
 * @top: Head of double list
 * @line_number: Line num
 * Return: None
 */
void _div(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n /= value;
}

/**
 * _mul - Multiplies the second top element with the first element
 * @top: Head of double list
 * @line_number: Line num
 * Return: None
 */
void _mul(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n *= value;
}

/**
 * _mod - computes the rest of the division of the second
 *  top element of the stack by the top element of the stack
 * @top: Head of double list
 * @line_number: Line num
 * Return: None
 */
void _mod(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n %= value;
}

/**
 * _pchar - Prints the char at the top of the stack
 * @top: Head of double list
 * @line_number: Line num
 * Return: None
 */
void _pchar(stack_t **top, unsigned int line_number)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n > 127 || (*top)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*top)->n);
}

/**
 * _pstr - Prints the string starting at the top of the stack
 * @top: Head of double list
 * @line_number: Line num
 * Return: None
 */
void _pstr(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int x;
	(void)line_number;

	for (x = 0; current && current->n != 0 &&
				!(current->n > 127 || current->n < 0);
		 x++)
	{
		fprintf(stdout, "%c", current->n);
		current = current->next;
	}
	fprintf(stdout, "\n");
}

/**
 * _rotl - Rotates the stack to the top
 * @top: Head of double list
 * @line_number: Line num
 * Return: None
 */
void _rotl(stack_t **top, unsigned int line_number)
{
	stack_t *last = *top;
	int x;

	if (!*top)
		return;
	(void)line_number;
	for (x = 0; last; x++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *top;
	(*top)->prev = last;
	(*top) = (*top)->next;
	(*top)->prev->next = NULL;
	(*top)->prev = NULL;
}

/**
 * _rotr - Rotates the stack to the bottom
 * @top: Head of double list
 * @line_number: Line num
 * Return: None
 */
void _rotr(stack_t **top, unsigned int line_number)
{
	stack_t *last = *top;
	int x;

	if (!*top || (*top)->next == NULL)
		return;
	(void)line_number;
	for (x = 0; last; x++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *top;
	last->prev->next = NULL;
	(*top)->prev = last;
	(*top) = last;
	last->prev = NULL;
}

