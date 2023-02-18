package com.example.teacherasistant

import android.content.Context
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import androidx.navigation.findNavController
import androidx.recyclerview.widget.RecyclerView
import com.example.teacherasistant.callback.FragmentCallback
import com.example.teacherasistant.viewmodels.MarkListViewModel

/**
 * A simple [Fragment] subclass.
 */
class MarkListFragment : Fragment() {
    private lateinit var _markListViewModel: MarkListViewModel
    private lateinit var _markListAdapter: MarkListAdapter

    private var _subjectId: Long? = null
    private var _studentId: Long? = null

    private var callback: FragmentCallback? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val args = arguments?.let {
            MarkListFragmentArgs.fromBundle(it)
        }

        if (args != null) {
            _subjectId = args.subjectId
            _studentId = args.studentId
        }
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val view = inflater.inflate(R.layout.fragment_mark_list, container, false)

        val markListRecyclerView: RecyclerView = view.findViewById(R.id.mark_list_recycler_view)

        _markListViewModel = MarkListViewModel(activity as Context, _subjectId!!, _studentId!!)
        _markListViewModel.marks.observe(viewLifecycleOwner) {
            _markListAdapter = MarkListAdapter(it, _markListViewModel)
            markListRecyclerView.adapter = _markListAdapter
        }

        val addMarkButton: Button = view.findViewById(R.id.add_mark_button)
        addMarkButton.setOnClickListener {
            val action = MarkListFragmentDirections.actionMarkListFragmentToMarkCreatorFragment(
                _subjectId!!,
                _studentId!!
            )

            view.findNavController().navigate(action)
        }

        return view
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        if (callback != null) {
            changeText("Lista ocen")
        }
    }

    override fun onAttach(context: Context) {
        super.onAttach(context)
        callback = context as FragmentCallback
    }

    override fun onDetach() {
        super.onDetach()
        callback = null
    }

    fun changeText(text: String) {
        callback?.onFragmentChanged(text)
    }
}